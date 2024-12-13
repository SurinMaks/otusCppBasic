#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

#include "line_separator.h"

void unique()
{
    LineSeparator::out(" Example 1: testUnique");

    std::map<int, std::string> values;

    // access by key
    // maybe rewrite or insert
    values[24] = "Who is it?";
    std::cout << values[5] << std::endl;

    // maybe rewrite
    /*std::pair<
        std::map<int,std::string>::iterator,
        bool
    > ret;*/
    auto result = values.insert(std::make_pair(42, "Petia"));

    std::cout << result.first->first << " <-> ";
    std::cout << result.first->second << ". inserted: " << result.second << std::endl;

    result = values.insert(std::make_pair(42, "Vasia"));
    std::cout << result.first->first << " <-> ";
    std::cout << result.first->second << ". inserted: " << result.second << std::endl;
}

void order()
{
    LineSeparator::out(" Example 2: order");

    std::map<std::string, int> values = {
        {"Vasia",  10},
        {"Petia",  42},
        {"Marina", 17},
        {"Mike",   22},
        {"Alex",   1}
    };

    for (const auto& v: values)
    {
        std::cout << v.first << std::endl;
    }

    std::map<std::string, int, std::greater<std::string>> values2 = {
        {"Vasia",  10},
        {"Petia",  42},
        {"Marina", 17},
        {"Mike",   22},
        {"Alex",   1}
    };

    for (const auto& v: values2)
    {
        std::cout << v.first << v.second << std::endl;
    }

    for (const auto& [key, _] : values)
    {
        std::cout << key << " " << value << std::endl;
    }
}

void iterator()
{
    LineSeparator::out(" Example 3: iterator");

    std::map<std::string, int> values = {
        {"Alpha",   1},
        {"Bravo",   2},
        {"Charlie", 3},
        {"Delta",   4},
        {"Echo",    5}
    };

    auto iter = values.begin();
    std::cout << iter->first << " " << iter->second << std::endl;

    // Bidirectional
    ++iter;
    --iter;

    // But not random-access
    // iter += 3;

    std::advance(iter, 2);
    std::cout << iter->first << " " << iter->second << std::endl;
}

void find()
{
    std::map<std::string, int> values = {
            {"Vasia",  10},
            {"Petia",  42}
    };

    auto a = values.find("Vasia");
    std::cout << "Found: " << a->first << " : " << a->second << std::endl;

    auto b = values.find("Ann");

    if (b == values.end()) {
        std::cout <<  "Not found: Ann" << std::endl;
    }
}

struct S
{
    S(const std::string& v)
    : val(v)
    {}
    std::string val;
};

bool operator<(const S& s1, const S& s2)
{
    return s1.val < s2.val;
}

void custom()
{
    std::map<S, std::string> m {{S("b"), "val"}, {S("a"), "val"}};
    for (const auto& [key, value] : m)
    {
        std::cout << key.val << " " << value << std::endl;
    }
}


int main()
{
    unique();
    order();
    iterator();
    find();
    custom();
}
