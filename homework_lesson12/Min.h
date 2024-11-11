#ifndef _MIN_H_
#define _MIN_H_
#include "IStatistics.h"
class Min : public IStatistics {
public:
	Min();

	void update(double next) override;

	double eval() const override;

	const char * name() const override;

private:
	double m_min;
};

#endif