#ifndef _MYCONTAINER_H_
#define _MYCONTAINER_H_

/**
 * Шаблонный класс для односвязного списка
 */
template<typename T>
class MyContainer {
    public:
    virtual ~MyContainer(){};
    virtual void push_bach(const T& value) = 0;
    virtual void insert(const T& value, const unsigned int position) = 0;
    virtual void erase(const unsigned int position) = 0;
    virtual unsigned int size() = 0;
    //operator[] хз че с ним делать ПОДУМАТЬ
};

#endif
