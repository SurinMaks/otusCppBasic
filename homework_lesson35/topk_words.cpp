// Read files and prints top k word by frequency

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <vector>
#include <future>
#include <thread>

#include "func.hpp"

int main(int argc, char *argv[]) {

    const size_t TOPK = 10;

    if (argc < 2) {
        std::cerr << "Usage: topk_words [FILES...]\n";
        return EXIT_FAILURE;
    }

    auto start = std::chrono::high_resolution_clock::now();
    Counter freq_dict; //словарь частотности слов
    std::mutex mtx;
    std::vector<std::thread> threadCalcs; // тут будем хранить потоки вычислений
    for (int i = 1; i < argc; ++i) {
        threadCalcs.emplace_back(count_words, argv[i], std::ref(freq_dict), std::ref(mtx));
    }

    for(auto& threadCalc : threadCalcs ){
        threadCalc.join();
  }

    print_topk(std::cout, freq_dict, TOPK);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
}