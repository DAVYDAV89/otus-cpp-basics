#ifndef STD_H
#define STD_H

#include "istatistics.h"
#include <iostream>
#include <vector>

class Std : public IStatistics {
public:
    Std();

    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    int                     m_count;
    double                  m_std;

    double                  m_val;
    std::vector<double>     m_vec;
};

#endif // STD_H
