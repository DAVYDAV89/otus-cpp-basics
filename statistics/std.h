#ifndef STD_H
#define STD_H

#include "istatistics.h"

class Std : public IStatistics {
public:
    Std();

    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    double  m_std;
    int     m_count;
};

#endif // STD_H
