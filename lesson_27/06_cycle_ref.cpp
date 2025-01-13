#include <iostream>
#include <memory>

struct SomeStruct
{
    SomeStruct()
    {
        std::cout << "Constructor!" << '\n';
    }

    ~SomeStruct()
    {
        std::cout << "Desctructor!" << '\n';
    }

    std::shared_ptr<SomeStruct> partner;
};

void function_with_leakage()
{
    auto partnerA = std::make_shared<SomeStruct>();
    auto partnerB = std::make_shared<SomeStruct>();
    partnerA->partner = partnerB;
    partnerB->partner = partnerA;
}

int main()
{
    function_with_leakage();
}
