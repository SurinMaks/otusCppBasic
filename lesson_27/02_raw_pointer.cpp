int main()
{
    // 1
    {
        auto* ptr = new int{10};
        // ...
        delete ptr;
    }

    // 2
    {
        auto value = 10;
        auto ptr = new int{10};
        // ...
        // Указатель на выделенную память потерян
        ptr = &value;
    }

    // 3
    {
        auto ptr = new int[10]{};
        // ...
        delete[] ptr;
    }

    // 4
    {
        auto ptr = new int[10];
        // Выход из функции до освобождения ресурсов
        // if (...) {
        //
        // } else if (...) {
        //     ...
        // } else if (...) {
        //
        //     return ... !!!!!!!
        // } ...
        delete[] ptr;
    }
}

// Вернемся к презентации, слайд "Недостатки сырых указателей".
