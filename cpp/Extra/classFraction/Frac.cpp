#include "Frac.h"

int pgcd(int a, int b){
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

Frac operator+(Frac & a, Frac const& b)
{
    return a.additionne(b);
}

Frac operator-(Frac & a, Frac const& b)
{
    return a.soustrait(b);
}

Frac::Frac(int num, int den) : m_num(num), m_den(den)
{
    m_num /= pgcd(num, den);
    m_den /= pgcd(num, den);
}

Frac Frac::additionne(Frac const& b)
{
    Frac result(m_num * b.m_den + b.m_num * m_den, m_den * b.m_den);
    return result;
}

Frac Frac::soustrait(Frac const& b)
{
    Frac result(m_num * b.m_den - b.m_num * m_den, m_den * b.m_den);
    return result;
}