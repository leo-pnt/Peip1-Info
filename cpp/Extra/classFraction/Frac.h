#include <iostream>

class Frac {
public:
    Frac(int num = 0, int den = 0);

    friend std::ostream& operator<<(std::ostream &out, Frac const& self) {
        out<<"("<<self.m_num<<","<<self.m_den<<")";
        return out;
    }

    Frac additionne(Frac const& b);
    Frac soustrait(Frac const& b);
private:
    int m_num; //numerateur
    int m_den; //denominateur
};

Frac operator+(Frac & a, Frac const& b);
Frac operator-(Frac & a, Frac const& b);
int pgcd(int a, int b);