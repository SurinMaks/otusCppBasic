#include "include/MyList.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    //не работает, говорит нет конструктора
    // MyList myList = new MyList();
    MyList myList = new MyList(3);
    std::cout << myList.size() << '\n';
    return 0;
}
