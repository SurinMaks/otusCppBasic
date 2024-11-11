#ifndef _MEAN_H_
#define _MEAN_H_
#include "IStatistics.h"

class Mean : public IStatistics{
    void update(double next) override;

    double eval() const override;

    const char * name() const;

    private:
        double m_mean;
        double m_temp = 0.0;
        int m_count=1;

};

#endif

