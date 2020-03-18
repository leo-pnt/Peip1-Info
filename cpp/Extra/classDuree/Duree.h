#include <iostream>

class Duree {
public:
    Duree(int heure = 0, int minute = 0, int seconde = 0);

    friend std::ostream& operator<<(std::ostream& out, Duree const& self) {
        out <<"("<<self.m_heure<<","<<self.m_minute<<","<<self.m_seconde<<")";
        return out;
    }

    bool operator==(Duree const& b) {
        return (m_heure == b.m_heure && m_minute == b.m_minute && m_seconde == b.m_seconde);
    }

    bool operator!=(Duree const& b) {
        return !(m_heure == b.m_heure && m_minute == b.m_minute && m_seconde == b.m_seconde);
    }

    
private:
    int m_heure;
    int m_minute;
    int m_seconde;
};