#include "std.h"
#include <math.h>
#include <iostream>

Std::Std()
    : m_val(0)
    , m_std(0)
    , m_count(0)
{

}

void Std::update(double next)
{
    m_count++;
    m_vec.push_back(next);
    m_val += next;

    m_std = 0;
    for (const auto &_el : m_vec)
        m_std += ( (_el - m_val/m_count)*(_el - m_val/m_count) );
}

double Std::eval() const
{
    return sqrt(m_std / m_count);
}

const char *Std::name() const {
    return "Std";
}

