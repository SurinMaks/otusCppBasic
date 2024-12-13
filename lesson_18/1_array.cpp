#include <array>
#include <iostream>
#include <stdexcept>

void asCArray()
{
    // Fixed type. Fixed size. Stack
    int cArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10> ar = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ar[1] = 20;

    for (std::size_t i = 0; i < ar.size(); ++i)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << '\n';

    for (auto it = ar.begin(); it != ar.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    for (auto it = ar.cbegin(); it != ar.cend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    for (const auto& i: ar)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void constCorrectness()
{
    std::array<const int, 10> constElements = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //constElements[4] = 1;    // Compile error: can not assign to const item

    const std::array<int, 10> constArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //constArray[5] = 55;      // Compile error: can not assign to const item
}

void elementsAccess()
{
    const std::array<int, 10> ar = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // or const int& v =
    int v = ar[5];
    std::cout << "Element at index 5: " << v << '\n';

    // memory block
    const int* data_ptr = ar.data();
    data_ptr += 3;
    std::cout << "Dereference data_ptr is: " << *data_ptr << '\n';
    // for c-style library

    // as pointer arifm
    auto it = ar.begin();
    it += 3;
    std::cout << "Dereference it is: " << *it << '\n';

    // Oops
    //std::cout << ar[10] << '\n'; //undefined behavior like in C


    try
    {
        std::cout << ar.at(10) << '\n';
    }
    catch (const std::out_of_range& ex)
    {
        std::cerr << "Exception: " << ex.what() << '\n';
    }
}

void cpp17()
{
    const std::array cpp17_1 = {1, 2, 3};


    struct S {
        S(int){}
    };
    const auto cpp17_2 = std::array{S(42), S(12), S(21)};
}

int main()
{
    asCArray();
    constCorrectness();
    elementsAccess();
    cpp17();
}
