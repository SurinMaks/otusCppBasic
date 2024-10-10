#include "random_value.hpp"
#include <ctime>
#include <cstdlib>

int get_random_value(unsigned int max_value)
{
    std::srand(std::time(nullptr));
    return std::rand() % max_value;
}