#include "mean.h"

Mean::Mean()
    : m_mean(0)
    , m_count(0)
{

}

void Mean::update(double next)
{
    m_count++;
    m_mean += next;
}

double Mean::eval() const
{
    return m_mean / m_count;
}

const char *Mean::name() const {
    return "mean";
}

