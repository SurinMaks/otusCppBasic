// Передача по ссылке данных в поток

#include <cstddef>     // Для работы с базовыми типами данных
#include <fstream>     // Для работы с файлами
#include <iostream>    // Для ввода-вывода
#include <iterator>    // Для работы с итераторами
#include <ostream>     // Для потоков вывода
#include <thread>      // Для работы с потоками
#include <vector>      // Для работы с векторами

// Определяем путь к "пустому" файлу в зависимости от операционной системы
#if defined(__linux__) || defined(__APPLE__)
const char *null = "/dev/null"; // Для Linux и MacOS используем /dev/null
#elif defined(_WIN32)
const char *null = "NUL"; // Для Windows используем NUL
#else
#error platform not supported // Если платформа неизвестна, генерируем ошибку компиляции
#endif

// Функция создания фонового потока для сохранения файла
std::thread savefile_bg(const std::string &filename, const std::vector<char> &buffer) {
    return std::thread( // Создаём и возвращаем новый поток
        // Лямбда-функция, которая будет выполняться в отдельном потоке
        [](const std::vector<char> &buffer, const std::string filename) {
            std::ofstream out(filename);             // Открываем файл для записи
            out.write(buffer.data(), buffer.size()); // Записываем данные из буфера в файл
            out.close();                             // Закрываем файл
            std::clog << "File written\n";           // Выводим сообщение об успешной записи
        },
        buffer, filename); // Передаём аргументы в лямбда-функцию
}

int main() {
    // Создаём буфер размером ~40MB, заполненный символами 'A'
    std::vector<char> buffer(10 * 4096 * 4096, 'A');

    // Создаём фоновую задачу для записи буфера в файл

    // Отсоединяем поток, позволяя ему работать независимо
    bg_task.detach();

    // Ждём нажатия клавиши перед завершением программы
    std::getchar();
}