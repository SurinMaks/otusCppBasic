#include "result.hpp"
#include <iostream>
#include <fstream>
#include <string> 

bool check_value(int random_value, unsigned int user_value)
{
    if(user_value == random_value)
    {
        return true;
    }

    if (user_value < random_value)
    {
        std::cout << "greater than " << user_value << std::endl;
    }
    else
    {
        std::cout << "less than " << user_value << std::endl;
    }

    return false;
}

void write_result_to_file(const std::string &file_name, const std::string &user_name, unsigned int number_of_tries)
{
    std::ofstream out(file_name, std::ios::app);
    if(out.is_open())
    {
        out << user_name << ' ' << number_of_tries << '\n';
    }
    out.close();

}

void read_result_from_file(const std::string &file_name)
{
    std::string line;
    std::ifstream in(file_name);
    std::cout << "High scores table:" << std::endl;
    if(in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
        
    }
}