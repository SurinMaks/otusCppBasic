#ifndef _MYLIST_H_
#define _MYLIST_H_

#include "MyContainer.hpp"
#include <iostream>

template<typename T>
class MyList : public MyContainer<T> {
public:
        MyList() = delete;

        MyList(const T& value){
            push_bach(value);
        };

        ~MyList() {

        };

        void push_bach(const T& value) override {
            struct MyNode* newNode = new struct MyNode(value);
            if(!m_head){ //проверка на пустой список
                m_head = newNode;
            }
            else{
                struct MyNode* new_Node = m_head;
                while (new_Node->m_next) //когда список не пустой перемещаемся в конец
                {
                    new_Node = new_Node->m_next;
                }
                new_Node->m_next = newNode;
                
            }
            incrementSize();
        };

        void insertFromPosition(const T& value, const unsigned int position) override {
            incrementSize();
        };

        void insertFromEnd(const T& value) override{
            push_bach(value);

        };
        void insertFromBegin(const T& value) override{
            struct MyNode* new_Node = new struct MyNode(value);
            new_Node->m_next = m_head;
            m_head = new_Node;
            incrementSize();
        };

        void eraseFromPosition(const unsigned int position) override {
            if ((position > m_size) || (position == 0)){
                std::cout << "Index out of range list. From position " << position << '\n';
                return;
            }
            if(position == 1){
                eraseFromBegin();
                return;
            }
            if(position == m_size){
                eraseFromEnd();
                return;
            }
            struct MyNode* tmp_Node = m_head;
            for (unsigned int i = 1; i < position-1; ++i){
                tmp_Node = tmp_Node->m_next;
            }
            struct MyNode* nodeDelete = tmp_Node->m_next;
            tmp_Node->m_next = tmp_Node->m_next->m_next;
            delete nodeDelete;
            decrementSize();
        };

        void eraseFromEnd() override {
            if(checkTheEmptyList()){
                return;
            } 
            if(!m_head->m_next){
                delete m_head;
                m_head = nullptr;
                decrementSize();
                return;
            }
            struct MyNode* del_Node = m_head;
            while (del_Node->m_next->m_next)
            {
                del_Node = del_Node->m_next;
            }
            delete del_Node->m_next;
            del_Node->m_next = nullptr;
            decrementSize();
            
            
        };

        void eraseFromBegin() override{
            if(checkTheEmptyList()){
                return;
            } 
            MyNode* del_Node = m_head;
            m_head = m_head->m_next;
            delete del_Node;
            decrementSize();
            
        };

        unsigned int size() const override {
            return m_size;
        };

        void printList() const override{
            if(!m_head){
                std::cout << "List is empty\n";
            }
            else{
                struct MyNode* temp = m_head;
                while (temp)
                {
                    std::cout << temp->m_value << ' ';
                    temp = temp->m_next;
                }
                std::cout << '\n';
            }
        };

        //operator[] хз че с ним делать ПОДУМАТЬ
private:
        struct MyNode
        {
            MyNode(const T& value){
                m_value = value;
                m_next = nullptr;
            }
            T m_value;
            MyNode* m_next;
        };

        bool checkTheEmptyList(){
            if(!m_head){
                std::cout << "List is empty\n";
                return true;
            }
            else{
                return false;
            }
        };

        void incrementSize(){
            ++m_size;
        };

        void decrementSize(){
            --m_size;
        };
        struct MyNode* m_head = nullptr;
        unsigned int m_size = 0;
};

#endif
