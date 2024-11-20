#ifndef _MYARRAY_H_
#define _MYARRAY_H_

#include "MyContainer.hpp"
#include <iostream>
#include <memory>

template <typename T>
class MyArray : public MyContainer<T> {
 
 public:
    MyArray(){
    };

    ~MyArray(){};

    void push_back(const T& value) override {
        std::unique_ptr<int[]> new_array = std::make_unique<int[]>(m_size+1);
        for(unsigned int i = 0; i < m_size; ++i){
            new_array[i] = m_array[i];
        }
        new_array[m_size] = value;
        m_array = std::move(new_array);
        incrementSize();
    };

    void insertFromPosition(const T& value, const unsigned int position) override {
        if(position < 1 || position > m_size){
            std::cout << "Index out of range\n";
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
        std::unique_ptr<int[]> new_array = std::make_unique<int[]>(m_size+1);
        for(unsigned int i = 0; i < m_size; ++i){
            if(i < position-1){
                new_array[i] = m_array[i];
            }
            if(i == position-1){
                new_array[i] = value;
            }
            if(i > position-2){
                new_array[i+1] = m_array[i];
            }
        }
        
        m_array = nullptr;
        m_array = std::move(new_array);
        incrementSize();

        
    };

    void insertFromEnd(const T& value) override {
        push_back(value);

    };

    void insertFromBegin(const T& value) override {
        std::unique_ptr<int[]> new_array = std::make_unique<int[]>(m_size+1);
        new_array[0] = value;
        for(unsigned int i = 0; i < m_size; ++i){
            new_array[i+1] = m_array[i];
        }
        m_array = std::move(new_array);
        incrementSize();

    };

    void eraseFromPosition(const unsigned int position) override {
        if(position < 1 || position > m_size){
            std::cout << "Index out of range\n";
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
        std::unique_ptr<int[]> new_array = std::make_unique<int[]>(m_size-1);
        for(unsigned int i = 0; i < m_size; ++i){
            if(i < position - 1){
                new_array[i] = m_array[i];
            }
            if(i == position - 1){
                ++i;
            }
            if(i > position - 2){
                new_array[i-1] = m_array[i];
            }
        }
        m_array = std::move(new_array);
        decrementSize();

    };

    void eraseFromEnd() override {
        if(0 == m_size){
            std::cout << "Array is empty\n";
            return;
        }
        std::unique_ptr<int[]> new_array = std::make_unique<int[]>(m_size-1);
        for(unsigned int i = 0; i < m_size-1; ++i){
            new_array[i] = m_array[i];
        }
        m_array = std::move(new_array);
        decrementSize();
    };

    void eraseFromBegin() override {
        if(0 == m_size){
            std::cout << "Array is empty\n";
            return;
        }
        std::unique_ptr<int[]> new_array = std::make_unique<int[]>(m_size-1);
        for(unsigned int i = 1; i < m_size; ++i){
            new_array[i-1] = m_array[i];
        }
        m_array = std::move(new_array);
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
        return m_array[index-1];
    };
private:

    void incrementSize(){
        ++m_size;
    }

    void decrementSize(){
        --m_size;
    }

    int m_size = 0;
    std::unique_ptr<int[]> m_array = std::make_unique<int[]>(m_size);

};

#endif