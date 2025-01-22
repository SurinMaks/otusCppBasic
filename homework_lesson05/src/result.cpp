#include "result.hpp"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <map>
#include <set>

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

void read_result_from_file_only_records(const std::string &file_name)
{
    std::string line;
    std::ifstream in(file_name);    
    std::string user_name;
    int number_of_tries;
    std::vector<std::string> tokens;
    std::multimap<std::string, int> users_tries;
    std::set<std::string> uniqueKeys;
    std::cout << "High scores table:" << std::endl;

    if(in.is_open())
    {
        while (std::getline(in, line))
        {
            split(line, " ", tokens);
            users_tries.insert({tokens[0],stoi(tokens[1])});
            tokens.clear();
        }
    }    

    for(auto& it : users_tries)
    {
        uniqueKeys.insert(it.first);
    }

    for (const auto& key : uniqueKeys) {
        int min = 0;
        auto range = users_tries.equal_range(key);
        for(auto it = range.first; it != range.second; ++it)
        {
            min = it -> second;
            if(it -> second < min)
            {
                min = it -> second;
            }
        }      
        std::cout << key << ' ' << min << std::endl;
    }
}

void split(const std::string& str, const std::string& delimiters , std::vector<std::string>& tokens)
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}