#include "include/MyList.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    MyList myList0{0};
    myList0.push_bach(1);
    myList0.push_bach(2);
    myList0.push_bach(3);
    myList0.push_bach(4);
    myList0.push_bach(5);
    myList0.push_bach(6);
    myList0.push_bach(7);
    myList0.push_bach(8);
    myList0.push_bach(9);
    myList0.printList();
    std::cout << "Size=" << myList0.size() << '\n';
    
    myList0.eraseFromPosition(3);
    myList0.eraseFromPosition(5);
    myList0.eraseFromPosition(7);
    myList0.printList();

    myList0.insertFromBegin(10);
    myList0.printList();

    myList0.insertFromPosition(20,5);
    myList0.printList();

    myList0.insertFromEnd(30);
    myList0.printList();
    std::cout << "Size=" << myList0.size() << '\n';
    std::cout << myList0[10] << '\n';

    return 0;
}
