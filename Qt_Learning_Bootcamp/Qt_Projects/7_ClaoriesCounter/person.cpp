#include "person.h"

Person::Person() {}

void Person::set_weight(double weight)
{
    m_weight = weight;
}

void Person::set_time(double time)
{
    m_time = time;

}

void Person::set_speed(double speed)
{
    m_speed = speed;
}

double Person::get_weight()
{
    return m_weight;
}

double Person::get_time()
{
    return m_time;
}

double Person::get_speed()
{
    return m_speed;
}
