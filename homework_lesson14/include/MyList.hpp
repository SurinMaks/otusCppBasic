#ifndef _MYLIST_H_
#define _MYLIST_H_

#include "MyContainer.hpp"

template<typename T>
class MyList : public MyContainer<T> {
public:
        MyList(){
            MyNode* myNode = new MyNode();
            incrementSize();
        };

        MyList(const T& value){
            MyNode* myNode = new MyNode(value);
             incrementSize();
        };

        ~MyList() override {

        };

        void push_bach(const T& value) override {
            incrementSize();
        };

        void insert(const T& value, const unsigned int position) override {
            incrementSize();
        };

        void erase(const unsigned int position) override {
            decrementSize();
        };

        unsigned int size() override {
            return m_size;
        };

        //operator[] хз че с ним делать ПОДУМАТЬ
private:
        void incrementSize(){
            ++m_size;
        }
        void decrementSize(){
            --m_size;
        }
        struct MyNode
        {
            MyNode(){
                m_next = nullptr;
            }

            MyNode(const T& value){
                m_value = value;
                m_next = nullptr;
            }
            T m_value{};
            MyNode* m_next = nullptr;
        };
        MyNode* m_head{};
        unsigned int m_size = 0;
};

#endif
