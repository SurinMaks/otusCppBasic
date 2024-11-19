#include "include/MyList.hpp"
#include "include/MyArray.hpp"
#include <iostream>
#include <list>


int main(int argc, char const *argv[])
{
    std::cout << "Example List\n";
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
    
    myList0.eraseFromPosition(7);
    myList0.eraseFromPosition(5);
    myList0.eraseFromPosition(3);
    myList0.printList();

    myList0.insertFromBegin(10);
    myList0.printList();

    myList0.insertFromPosition(20,5);
    myList0.printList();

    myList0.insertFromEnd(30);
    myList0.printList();

    std::cout << "\nExample Array\n";
    MyArray<int> myArray;
    myArray.push_bach(0);
    myArray.push_bach(1);
    myArray.push_bach(2);
    myArray.push_bach(3);
    myArray.push_bach(4);
    myArray.push_bach(5);
    myArray.push_bach(6);
    myArray.push_bach(7);
    myArray.push_bach(8);
    myArray.push_bach(9);
    myArray.printList();
    std::cout << "Size=" << myArray.size() << '\n';

    myArray.eraseFromPosition(7);
    myArray.eraseFromPosition(5);
    myArray.eraseFromPosition(3);
    myArray.printList();

    myArray.insertFromBegin(10);
    myArray.printList();

    myArray.insertFromPosition(20,5);
    myArray.printList();

    myArray.insertFromEnd(30);
    myArray.printList();
    
    return 0;
}
