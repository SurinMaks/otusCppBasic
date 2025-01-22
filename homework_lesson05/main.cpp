#include <iostream>
#include "include/random_value.hpp"
#include "include/input_data.hpp"
#include "include/result.hpp"

int main(int argc, char const *argv[])
{
    bool correct_answer = false;
    unsigned int number_of_tries = 0;
    unsigned int max_value= 100;
    std::string file_name = "result.txt";
    short int illegalCombination = 0;

    for(int i = 1; i<=argc-1;++i)
    {
        std::string val = argv[i];
        if("-table" == val)
        {
            // read_result_from_file(file_name);
            read_result_from_file_only_records(file_name);
            return 0;
        }

        if("-level" == val)
        {
            ++i;
            max_value = set_level(atoi(argv[i]));
            ++illegalCombination;
        }

       if("-max" == val)
        {
            ++i;
            max_value = atoi(argv[i]);
            ++illegalCombination;
        }

        if(illegalCombination > 1)
        {
            std::cout << "Illegal combination\n";
            return 1;
        }

    }

    int random_value = get_random_value(max_value);
    std::cout << "random_value = " << random_value << std::endl;

    std::string user_name = get_name();
    
    std::cout << "Enter your guess:\n";
    
    do
    {
        correct_answer = check_value(random_value, get_number());
        ++number_of_tries;
    } 
    while (!correct_answer);
    write_result_to_file(file_name, user_name, number_of_tries);
    std::cout << "you win! " << "attempts = " << number_of_tries << std::endl;     
    // read_result_from_file(file_name);   
    read_result_from_file_only_records(file_name);
    

    return 0;
}
