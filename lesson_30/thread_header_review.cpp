/*
std::thread() - создание пустого потока
get_id() - получить ID потока
joinable() - проверить можно ли присоединить
join() - дождаться завершения потока
detach() - отсоединить поток от основного потока
swap() - поменять потоки местами
native_handle() - получить системный идентификатор потока
hardware_concurrency() - узнать число аппаратных потоков

std::this_thread::get_id() - ID текущего потока
std::this_thread::yield() - уступить время другому потоку
std::this_thread::sleep_for() - поспать заданное время
std::this_thread::sleep_until() - поспать до указанного момента
*/

#include <iostream>
#include <thread>
#include <chrono>

// Простая функция для демонстрации
void printHello() {
    std::cout << "Привет из потока!\n";
}

int main() {
    // std::thread() - пустой поток
    std::thread empty;
    std::cout << "Пустой поток создан\n";

    // std::thread(Function) - поток с функцией
    std::thread t1(printHello);
    t1.join();

    // get_id() - получить ID потока
    std::thread t2([]{ 
        std::cout << "ID этого потока: " << std::this_thread::get_id() << "\n"; 
    });
    t2.join();

    // joinable() - проверить можно ли присоединить
    std::thread t3(printHello);
    if(t3.joinable()) {
        std::cout << "Поток можно присоединить\n";
        t3.join();
    }

    // join() - ждать завершение потока
    std::thread t4([]{ 
        std::cout << "Начало работы\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Конец работы\n";
    });
    std::cout << "Ждем завершения потока...\n";
    t4.join();
    std::cout << "Поток завершился!\n";

    // detach() - отсоединить поток
    std::thread t5([]{ 
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Сообщение из отсоединенного потока\n"; 
    });
    t5.detach();
    std::cout << "Поток отсоединен\n";

    // swap() - поменять потоки местами
    std::thread t6([]{ std::cout << "Первый\n"; });
    std::thread t7([]{ std::cout << "Второй\n"; });
    t6.swap(t7);
    t6.join();
    t7.join();

    // native_handle() - получить системный хендл
    std::thread t8(printHello);
    //auto handle = t8.native_handle();
    std::cout << "Системный хендл получен\n";
    t8.join();

    // hardware_concurrency() - число доступных потоков
    std::cout << "Доступно потоков: " << std::thread::hardware_concurrency() << "\n";

    // this_thread::get_id() - ID текущего потока
    std::cout << "ID главного потока: " << std::this_thread::get_id() << "\n";

    // this_thread::yield() - уступить время
    std::cout << "Уступаем время другим потокам\n";
    std::this_thread::yield();

    // this_thread::sleep_for() - поспать
    std::cout << "Засыпаем на 1 секунду\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Проснулись!\n";

    // this_thread::sleep_until() - поспать до момента
    auto wakeTime = std::chrono::system_clock::now() + std::chrono::seconds(1);
    std::cout << "Спим до определенного момента\n";
    std::this_thread::sleep_until(wakeTime);
    std::cout << "Время пришло!\n";

    // Ждём секунду, чтобы увидеть сообщение от detach-нутого потока
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}
