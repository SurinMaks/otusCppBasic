#include "Mean.h" 

void Mean::update(double next){
    m_temp += next;
    m_mean = m_temp/m_count;
    ++m_count;

}

double Mean::eval() const{
    return m_mean;
}

const char * Mean::name() const{
    return "mean";
}

