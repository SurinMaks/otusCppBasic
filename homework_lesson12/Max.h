#ifndef _MAX_H_
#define _MAX_H_
#include "IStatistics.h"

class Max : public IStatistics {
public:
	void update(double next) override;

	double eval() const override;

	const char * name() const override;

private:
	double m_max;
	bool first = true;
};

#endif

