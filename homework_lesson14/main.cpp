#include "include/MyList.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    MyList myList0{1};
    // std::cout << "Size=" << myList0.size() << '\n';
    // myList0.eraseFromEnd();
    // std::cout << "Size=" << myList0.size() << '\n';
    myList0.push_bach(2);
    // std::cout << "Size=" << myList0.size() << '\n';
    myList0.push_bach(3);
    // std::cout << "Size=" << myList0.size() << '\n';
    myList0.push_bach(4);
    // myList0.eraseFromBegin();
    // std::cout << "Size=" << myList0.size() << '\n';
    myList0.push_bach(5);
    myList0.insertFromEnd(6);
    myList0.insertFromBegin(0);
    myList0.insertFromBegin(-1);
    // myList0.eraseFromBegin();
    // myList0.printList();
    // myList0.eraseFromPosition(3);
    // myList0.eraseFromPosition(3);
    myList0.eraseFromPosition(10);
    myList0.printList();
    std::cout << "Size=" << myList0.size() << '\n';
    return 0;
}
