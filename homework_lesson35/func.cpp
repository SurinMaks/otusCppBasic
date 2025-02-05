#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip>
#include <fstream>

#include "func.hpp"

// std::mutex mtx1;

std::string tolower(const std::string &str) {
    std::string lower_str;
    auto lmb = [](unsigned char ch) { return std::tolower(ch); };
    std::transform(std::cbegin(str), std::cend(str), std::back_inserter(lower_str), lmb);
    return lower_str;
};

void count_words(const char* stream, Counter& counter, std::mutex& mtx)
{
    Counter localCounter;

    std::ifstream inputFile{stream};
    auto f_tolower = [&localCounter](const std::string &s) { ++localCounter[tolower(s)]; };
    std::for_each(std::istream_iterator<std::string>(inputFile), std::istream_iterator<std::string>(), f_tolower);

    mtx.lock();
    for (const auto& pair : localCounter) {
        counter[pair.first] += pair.second;
    }
    mtx.unlock();
}

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
        std::begin(words), std::begin(words) + k, std::end(words),
        [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
        std::begin(words), std::begin(words) + k,
        [&stream](const Counter::const_iterator &pair) {
            stream << std::setw(4) << pair->second << " " << pair->first
                      << '\n';
        });
}