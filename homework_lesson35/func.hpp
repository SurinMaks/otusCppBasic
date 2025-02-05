#ifndef _FUNC_HPP_
#define _FUNC_HPP_

#include <iostream>
#include <map>
#include <mutex>

    using Counter = std::map<std::string, std::size_t>;

    std::string tolower(const std::string &str);

    void count_words(const char* stream, Counter&, std::mutex& mtx);

    void print_topk(std::ostream& stream, const Counter&, const size_t k);

    int countLines(std::ifstream& file);

#endif