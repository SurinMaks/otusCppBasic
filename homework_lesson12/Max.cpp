#include "Max.h" 

void Max::update(double next) {
    if(first){
        first = false;
        m_max = next;
    }
    if (next > m_max) {
        m_max = next;
    }
};

double Max::eval() const {
    return m_max;
}

const char * Max::name() const {
    return "max";
}