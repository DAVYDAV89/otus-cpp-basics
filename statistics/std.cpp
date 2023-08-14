#include "std.h"
#include <iostream>

Std::Std()
    : m_std(0)
    , m_count(0)
{

}

void Std::update(double next)
{
    m_count++;
    m_std /= m_count;
    m_std += (next - m_std) * (next - m_std);
}

double Std::eval() const
{
    return m_std / m_count - 1;
}

const char *Std::name() const {
    return "Std";
}

