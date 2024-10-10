#include <string>
#include <iostream>
#include "input_data.hpp"

std::string get_name()
{
    std::cout << "Hi! Enter your name, please:\n";
    std::string user_name;
    std::cin >> user_name;
    return user_name;
}

unsigned int get_number()
{
    unsigned int user_number;
    std::cin >> user_number;
    return user_number;
}

short int set_level(int level)
{
    short int level1 = 10;
    short int level2 = 50;
    short int level3 = 100;
    short int levelDef = 100;

    switch (level)
    {
        case 1:
            return level1;
            break;
        case 2:
            return level2;
            break;
        case 3:
            return level3;
            break;
        default:
            std::cout << "Undifined level. Set default value.\n";
            return levelDef;
            break;
    }
}