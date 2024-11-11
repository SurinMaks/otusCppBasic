#include <iostream>
// #include <limits>
// #include <vector>
// #include <complex>
#include "IStatistics.h"
#include "Max.h"
#include "Mean.h"
#include "Min.h"
#include "StandardDeviation.h"

// class IStatistics {
// public:
// 	virtual ~IStatistics() {}

// 	virtual void update(double next) = 0;
// 	virtual double eval() const = 0;
// 	virtual const char * name() const = 0;
// };

// class Min : public IStatistics {
// public:
// 	Min() : m_min{std::numeric_limits<double>::max()} {
// 	}

// 	void update(double next) override {
// 		if (next < m_min) {
// 			m_min = next;
// 		}
// 	}

// 	double eval() const override {
// 		return m_min;
// 	}

// 	const char * name() const override {
// 		return "min";
// 	}

// private:
// 	double m_min;
// };

// class Max : public IStatistics {
// public:
// 	void update(double next) override {
// 		if(first){
// 			first = false;
// 			m_max = next;
// 		}
// 		if (next > m_max) {
// 			m_max = next;
// 		}
// 	}

// 	double eval() const override {
// 		return m_max;
// 	}

// 	const char * name() const override {
// 		return "max";
// 	}

// private:
// 	double m_max;
// 	bool first = true;
// };

// class Mean : public IStatistics{
// 	void update(double next) override{
// 		m_temp += next;
// 		m_mean = m_temp/m_count;
// 		++m_count;

// 	}

// 	double eval() const override{
// 		return m_mean;
// 	}

// 	const char * name() const{
// 		return "mean";
// 	}

// 	private:
// 		double m_mean;
// 		double m_temp = 0.0;
// 		int m_count=1;

// };

// class StandardDeviation : public IStatistics{
// 	void update(double next) override{
// 		m_standardDeviation.push_back(next);
// 		m_sum += next;
// 		m_mean = m_sum/m_count;
// 		++m_count;
// 		for (double num : m_standardDeviation){
// 			m_valueStandardDeviation +=std::pow(num - m_mean,2);
// 		}
// 		 m_valueStandardDeviation = std::sqrt(m_valueStandardDeviation / m_standardDeviation.size());
// 	}

// 	double eval() const override{
// 		return m_valueStandardDeviation;
// 	}

// 	const char * name() const{
// 		return "std";
// 	}

// 	private:
// 		double m_mean = 0.0;
// 		double m_sum = 0.0;
// 		int m_count=1;
// 		std::vector<double> m_standardDeviation;
// 		double m_valueStandardDeviation = 0.0;
// };

int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new StandardDeviation{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}