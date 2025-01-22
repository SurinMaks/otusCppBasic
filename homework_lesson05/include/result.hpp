#ifndef _RESULT_H_
#define _RESULT_H_
#include <string> 
#include <vector>

bool check_value(int random_value, unsigned int user_value);
void write_result_to_file(const std::string &file_name, const std::string &user_name, unsigned int number_of_tries);
void read_result_from_file(const std::string &file_name);
void read_result_from_file_only_records(const std::string &file_name);
void split(const std::string& str, const std::string& delimiters , std::vector<std::string>& tokens);

#endif