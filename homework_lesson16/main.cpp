#include "include/MyList.hpp"
#include "include/MyArray.hpp"
#include <iostream>
#include <list>


int main(int argc, char const *argv[])
{
    std::cout << "Example List\n";
    MyList myList0{0};
    myList0.push_back(1);
    myList0.push_back(2);
    myList0.push_back(3);
    myList0.push_back(4);
    myList0.push_back(5);
    myList0.push_back(6);
    myList0.push_back(7);
    myList0.push_back(8);
    myList0.push_back(9);
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

    std::cout << "getList= " << myList0.getList() << '\n';

    std::cout << "\nExample Array\n";
    MyArray<int> myArray;
    myArray.push_back(0);
    myArray.push_back(1);
    myArray.push_back(2);
    myArray.push_back(3);
    myArray.push_back(4);
    myArray.push_back(5);
    myArray.push_back(6);
    myArray.push_back(7);
    myArray.push_back(8);
    myArray.push_back(9);
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

    std::cout << "getArray= " << myArray.getList() << '\n';
    
    return 0;
}
