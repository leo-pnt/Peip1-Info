#include "Duree.h"

Duree::Duree(int heure, int minute, int seconde) : m_heure(heure), m_minute(minute), m_seconde(seconde)
{
    if (m_seconde > 60) {
        m_minute += m_seconde / 60;
        m_seconde = m_seconde % 60;
    }

    if (m_minute > 60) {
        m_heure += m_minute / 60;
        m_minute = m_minute % 60;
    }
}