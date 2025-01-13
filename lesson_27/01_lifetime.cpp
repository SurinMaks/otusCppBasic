#include <iostream>

//static storage duration = duration of program of program
int global_val;

int foo()
{
    static int k = 0; //static storage duration
    return ++k;
}

int main()
{
    int local_val = 42; //automatic storage duration

    std::cout << foo() << '\n';

    auto heap_val = new int{10}; //dynamic storage duration

    // ...

    delete heap_val;
}
