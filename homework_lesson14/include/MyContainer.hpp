#ifndef _MYCONTAINER_H_
#define _MYCONTAINER_H_

/**
 * Класс для односвязного списка .. Пока сделаем для интов
 */
template<typename T>
class MyContainer {
    public:
    virtual ~MyContainer(){};
    virtual void push_bach(const T& value) = 0;
    virtual void insertFromPosition(const T& value, const unsigned int position) = 0;
    virtual void insertFromEnd(const T& value) = 0;
    virtual void insertFromBegin(const T& value) = 0;
    virtual void eraseFromPosition(const unsigned int position) = 0;
    virtual void eraseFromEnd() = 0;
    virtual void eraseFromBegin() = 0;
    virtual unsigned int size() const = 0;
    virtual void printList() const = 0;
    virtual T operator[](const T& index) const = 0;
};

#endif
