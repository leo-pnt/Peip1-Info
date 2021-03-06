#ifndef DEF_CINDIVIDU
#define DEF_CINDIVIDU

#include <iostream>
#include <string.h>

class CIndividu{
public:
    CIndividu();
    CIndividu(std::string nom, int age);
    ~CIndividu();

    friend std::ostream& operator<<(std::ostream& out, CIndividu const& self);
    friend std::istream& operator>>(std::istream& inIndi, CIndividu& self);

private:
    std::string m_nom;
    int m_age;
};

#endif