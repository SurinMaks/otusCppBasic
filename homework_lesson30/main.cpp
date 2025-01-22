#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>

#include "CRC32.hpp"
#include "IO.hpp"


static std::atomic_bool resultFound = false;

/// @brief Переписывает последние 4 байта значением value
void replaceLastFourBytes(std::vector<char> &data, uint32_t value) {
  std::copy_n(reinterpret_cast<const char *>(&value), 4, data.end() - 4);
}
void checkCRC32(const uint32_t& originalCrc32, std::vector<char> workData, std::vector<char>& result, const size_t num_start, const size_t maxVal){
  for (size_t i = num_start; i < maxVal; ++i) {
    if(resultFound.load()){
      return;
    }
    // Заменяем последние четыре байта на значение i
    replaceLastFourBytes(workData, uint32_t(i));
    // Вычисляем CRC32 текущего вектора result
    auto currentCrc32 = crc32(workData.data(), workData.size());
    if (currentCrc32 == originalCrc32) {
      std::cout << "Success\n";
      result = workData;
      resultFound.store(true);
      return;
    }
  }
}

/**
 * @brief Формирует новый вектор с тем же CRC32, добавляя в конец оригинального
 * строку injection и дополнительные 4 байта
 * @details При формировании нового вектора последние 4 байта не несут полезной
 * нагрузки и подбираются таким образом, чтобы CRC32 нового и оригинального
 * вектора совпадали
 * @param original оригинальный вектор
 * @param injection произвольная строка, которая будет добавлена после данных
 * оригинального вектора
 * @param n_threads количество потоков
 * @return новый вектор
 */
std::vector<char> hack(const std::vector<char> &original,
                       const std::string &injection,
                       uint n_threads) {

if (n_threads < 1){ // Проверяем корректность количества потоков
  throw std::logic_error("n_threads must be positive number"); // Завершаем программу с ошибкой
}
  const uint32_t originalCrc32 = crc32(original.data(), original.size());

  std::vector<char> tempData(original.size() + injection.size() + 4);
  auto it = std::copy(original.begin(), original.end(), tempData.begin());
  std::copy(injection.begin(), injection.end(), it);

  /*
   * Внимание: код ниже крайне не оптимален.
   * В качестве доп. задания устраните избыточные вычисления
   */
  const size_t maxVal = std::numeric_limits<uint32_t>::max();

  unsigned long batch_size = maxVal / (unsigned long)n_threads; // Вычисляем размер порции чисел для каждого потока
  std::vector<std::thread> threadCalcs; // тут будем хранить потоки вычислений
  std::vector<char> result;
  for (size_t i = 1; i < maxVal; i += batch_size) { // Распределяем работу между потоками
    threadCalcs.emplace_back(checkCRC32,std::ref(originalCrc32), tempData, std::ref(result), i, std::min(maxVal, i + batch_size));
  }

  for(auto& threadCalc : threadCalcs ){
    threadCalc.join();
  }

  if(resultFound.load()){
    return result;
  }
  else{
    throw std::logic_error("Can't hack");
  }
}

int main(int argc, char **argv) {
  std::chrono::time_point start = std::chrono::high_resolution_clock::now(); // Засекаем время начала вычислений
  if (argc < 3) {
    std::cerr << "Call with two args: " << argv[0]
              << " <input file> <output file>\n";
    return 1;
  }

  uint n_threads = (argc > 3) ? (uint)std::stoi(argv[3]) : std::thread::hardware_concurrency(); // Определяем количество потоков

  try {
    const std::vector<char> data = readFromFile(argv[1]);
    const std::vector<char> badData = hack(data, "He-he-he",n_threads);
    writeToFile(argv[2], badData);
  } catch (std::exception &ex) {
    std::cerr << ex.what() << '\n';
    return 2;
  }

  std::chrono::time_point end = std::chrono::high_resolution_clock::now(); // Засекаем время окончания вычислений
  std::chrono::duration<double> elapsed = end - start; // Вычисляем затраченное время
  std::cout << "It tooks " << elapsed.count() << " seconds with " << '\n';
  return 0;
}
