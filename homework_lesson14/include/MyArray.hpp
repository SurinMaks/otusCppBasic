#ifndef _MYARRAY_H_
#define _MYARRAY_H_

#include "MyContainer.hpp"
#include <iostream>

template <typename T>
class MyArray : public MyContainer<T> {
 
 public:
    MyArray(){
        T* m_array = new T[m_size];
    };

    ~MyArray(){};

    void push_bach(const T& value) override {
        T* new_array = new T[m_size+1];
        for(unsigned int i = 0; i < m_size; ++i){
            new_array[i] = m_array[i];
        }
        new_array[m_size] = value;
        m_array = nullptr;
        delete[] m_array;
        m_array = new_array;
        incrementSize();
    };

    void insertFromPosition(const T& value, const unsigned int position) override {
        
    };

    void insertFromEnd(const T& value) override {
        push_bach(value);

    };

    void insertFromBegin(const T& value) override {
        T* new_array = new T[m_size+1];
        new_array[0] = value;
        for(unsigned int i = 0; i < m_size; ++i){
            new_array[i+1] = m_array[i];
        }
        m_array = nullptr;
        delete[] m_array;
        m_array = new_array;
        incrementSize();

    };

    void eraseFromPosition(const unsigned int position) override {

    };

    void eraseFromEnd() override {
        if(0 == m_size){
            std::cout << "Array is empty\n";
            return;
        }
        T* new_array = new T[m_size-1];
        for(unsigned int i = 0; i < m_size-1; ++i){
            new_array[i] = m_array[i];
        }
        m_array = nullptr;
        delete[] m_array;
        m_array = new_array;
        decrementSize();
    };

    void eraseFromBegin() override {
        if(0 == m_size){
            std::cout << "Array is empty\n";
            return;
        }
        T* new_array = new T[m_size-1];
        for(unsigned int i = 1; i < m_size; ++i){
            new_array[i-1] = m_array[i];
        }
        m_array = nullptr;
        delete[] m_array;
        m_array = new_array;
        decrementSize();
    };

    unsigned int size() const override {
        return m_size;
    };

    void printList() const override {
        if(0 == m_size){
            std::cout << "Array is empty\n";
            return;
        }
        for (unsigned int i = 0; i < m_size; ++i){
            std::cout << m_array[i] << ' ';
        }
        std::cout << '\n';
    };  

    T operator[](const T& index) const override{

        if(index > m_size || m_size < 1){
            std::cout << "Index out of range\n";
            return{};
        }
        return m_array[index];
    };
private:

    void incrementSize(){
        ++m_size;
    }

    void decrementSize(){
        --m_size;
    }

    int m_size = 0;
    T* m_array;

};

#endif