#include "include/MyList.hpp"
#include "include/MyArray.hpp"
#include <iostream>
#include <list>


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
    // std::cout << "Size=" << myList0.size() << '\n';
    // std::cout << myList0[10] << '\n';



    // std::list<int> list1={0,1,2,3,4,5,6,7,8,9}; 
    
    // std::cout << "The original list is : "; 
    // for (std::list<int>::iterator i=list1.begin(); i!=list1.end(); i++) 
    //    std::cout << *i << " "; 
       
    // std::cout << std::endl;    

    // std::list<int>::iterator it = list1.begin(); 
    // std::list<int>::iterator it1 = list1.begin(); 
    // std::list<int>::iterator it2 = list1.begin();

    // advance(it,2);
    // advance(it1,4);
    // advance(it2,9);

    // list1.erase(it);
    // std::cout<<list1.size()<< '\n';
    // list1.erase(it1);
    // std::cout<<list1.size()<< '\n';
    // list1.erase(it2);
    // std::cout<<list1.size()<< '\n';

    // for (std::list<int>::iterator i=list1.begin(); i!=list1.end(); i++) 
    //    std::cout << *i << " "; 
    // std::cout << std::endl;
      
    // std::list<int>::iterator it = list1.begin(); 
    // advance(it,2);
    // list1.erase(it);

    // std::list<int>::iterator it1 = list1.begin();
    // advance(it1,4);
    // list1.erase(it1);

    // std::list<int>::iterator it2 = list1.begin();
    // advance(it2,6); 
    // list1.erase(it2);

    // for (std::list<int>::iterator i=list1.begin(); i!=list1.end(); i++) 
    //    std::cout << *i << " "; 
    // std::cout << std::endl;

    // // std::cout << "The original list is : "; 
    // // for (std::list<int>::iterator i=list1.begin(); i!=list1.end(); i++) 
    // //    std::cout << *i << " "; 
    // // std::cout << std::endl;
    // // std::cout<<list1.size()<< '\n';

    // // // list1.erase(it1);
    // // std::cout << "The original list is : "; 
    // // for (std::list<int>::iterator i=list1.begin(); i!=list1.end(); i++) 
    // //    std::cout << *i << " "; 
       
    // // std::cout << std::endl;
    // // std::cout<<list1.size()<< '\n';

    // // // list1.erase(it2);
    // // std::cout << "The original list is : "; 
    // // for (std::list<int>::iterator i=list1.begin(); i!=list1.end(); i++) 
    // //    std::cout << *i << " "; 
       
    // // std::cout << std::endl;
    // // std::cout<<list1.size()<< '\n';

    // // std::cout << "The original list is : "; 
    // // for (std::list<int>::iterator i=list1.begin(); i!=list1.end(); i++) 
    // //    std::cout << *i << " "; 
       
    // // std::cout << std::endl; 
    return 0;
}
