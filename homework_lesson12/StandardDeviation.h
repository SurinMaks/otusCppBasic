#ifndef _STANDARDDEVIATION_H_
#define _STANDARDDEVIATION_H_
#include "IStatistics.h"
#include "vector"

class StandardDeviation : public IStatistics{
	void update(double next) override;

	double eval() const override;

	const char * name() const override;

	private:
		double m_mean = 0.0;
		double m_sum = 0.0;
		int m_count=1;
		std::vector<double> m_standardDeviation;
		double m_valueStandardDeviation = 0.0;
};

#endif