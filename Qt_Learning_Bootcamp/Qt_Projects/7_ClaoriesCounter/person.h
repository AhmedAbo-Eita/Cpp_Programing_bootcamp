#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person();
    void set_weight(double weight);
    void set_time(double time);
    void set_speed(double speed);
    double get_weight();
    double get_time();
    double get_speed();

private:
    double m_weight;
    double m_time;
    double m_speed;


};

#endif // PERSON_H
