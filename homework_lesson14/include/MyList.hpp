#ifndef _MYLIST_H_
#define _MYLIST_H_

#include "MyContainer.hpp"
#include <iostream>
#include <memory>

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
            std::shared_ptr<struct MyNode> newNode = std::make_shared<struct MyNode>(value);
            newNode->m_next = nullptr;
            if(!m_head){ //проверка на пустой список
                m_head = newNode;
            }
            else{
                std::shared_ptr<struct MyNode> new_Node = m_head;
                while (new_Node->m_next) //когда список не пустой перемещаемся в конец
                {
                    new_Node = new_Node->m_next;
                }
                new_Node->m_next = newNode;
                
            }
            incrementSize();
        };

        void insertFromPosition(const T& value, const unsigned int position) override {
            if((position < 1) || position > m_size){
                std::cout << "Position should  be >= 1 and <=" << m_size << '\n';
                return;
            }
            if(position == 1){
                insertFromBegin(value);
                return;
            }
            if(position == m_size){
                insertFromEnd(value);
                return;
            }
            std::shared_ptr<struct MyNode> new_Node = std::make_shared<struct MyNode>(value);
            std::shared_ptr<struct MyNode> tmp_Node = m_head;
            for (unsigned int i = 1; i < position-1; ++i){
                tmp_Node = tmp_Node->m_next;
            }
            new_Node->m_next = tmp_Node->m_next;
            tmp_Node->m_next = new_Node;
            incrementSize();
        };

        void insertFromEnd(const T& value) override{
            push_bach(value);

        };
        void insertFromBegin(const T& value) override{
            std::shared_ptr<struct MyNode> new_Node = std::make_shared<struct MyNode>(value);
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
            std::shared_ptr<struct MyNode> tmp_Node = m_head;
            for (unsigned int i = 1; i < position-1; ++i){
                tmp_Node = tmp_Node->m_next;
            }
            std::shared_ptr<struct MyNode> nodeDelete = tmp_Node->m_next;
            tmp_Node->m_next = tmp_Node->m_next->m_next;
            decrementSize();
        };

        void eraseFromEnd() override {
            if(checkTheEmptyList()){
                return;
            } 
            if(!m_head->m_next){
                m_head = nullptr;
                decrementSize();
                return;
            }
            std::shared_ptr<struct MyNode> del_Node = m_head;
            while (del_Node->m_next->m_next)
            {
                del_Node = del_Node->m_next;
            }
            del_Node->m_next = nullptr;
            decrementSize();
            
            
        };

        void eraseFromBegin() override{
            if(checkTheEmptyList()){
                return;
            } 
            std::shared_ptr<struct MyNode> del_Node = m_head;
            m_head = m_head->m_next;
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
                std::shared_ptr<struct MyNode> temp = m_head;
                while (temp)
                {
                    std::cout << temp->m_value << ' ';
                    temp = temp->m_next;
                }
                std::cout << '\n';
            }
        };

         T operator[](const T& index) const override {
            std::shared_ptr<struct MyNode> tmp_Node = m_head;
            for (unsigned int i = 1; i < index; ++i){
                tmp_Node = tmp_Node->m_next;
            }
            return tmp_Node->m_value;
            
         };
private:
        struct MyNode
        {
            MyNode(const T& value){
                m_value = value;
                m_next = nullptr;
            }
            MyNode(){}
            T m_value;
            std::shared_ptr<struct MyNode> m_next = nullptr;
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
        
        std::shared_ptr<struct MyNode> m_head = nullptr;
        unsigned int m_size = 0;
};

#endif
