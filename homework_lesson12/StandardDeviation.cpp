#include "StandardDeviation.h" 
#include <vector>
#include <complex>

void StandardDeviation::update(double next){
    m_standardDeviation.push_back(next);
    m_sum += next;
    m_mean = m_sum/m_count;
    ++m_count;
    for (double num : m_standardDeviation){
        m_valueStandardDeviation +=std::pow(num - m_mean,2);
    }
        m_valueStandardDeviation = std::sqrt(m_valueStandardDeviation / m_standardDeviation.size());
}

double StandardDeviation::eval() const{
    return m_valueStandardDeviation;
}

const char * StandardDeviation::name() const{
    return "std";
}