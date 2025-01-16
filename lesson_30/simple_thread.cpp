#include <iostream>
#include <thread>

// Первый поток тупо пишет единицы
void fun1() {
    while(1) std::cout << "1" << std::endl;
}

// Второй поток пишет двойки
void fun2() {
    while(1) std::cout << "2" << std::endl;
}

int main() {
    // Создаем потоки
    std::thread t1(fun1);
    std::thread t2(fun2);
    
    // Ждем их (хотя в данном случае это вечное ожидание)
    t1.join();
    t2.join();
}
