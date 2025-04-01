#include <iostream>

class  Box{
public:
    //constructors
    Box();
    Box(double length, double width, double hight);


    //class methods
    void set_width(double width);
    void set_hight(double hight);
    void set_length(double length);
    double volum()const;


    //class attributes
private:
    double m_width;
    double m_hight;
    double m_length;

};

//impelementation
void Box::set_width(double width)
{
    m_width = width;
}
void Box::set_hight(double hight)
{
    m_hight = hight;
}
void Box::set_length(double length)
{
    m_length = length;
}

//Constructor impelementation
Box::Box()
{
    std::cout << "No parameter constructor called" << std::endl;
};
Box::Box(double length, double width, double hight)
{
    std::cout << "two parameter constructor called" << std::endl;
    m_length = length;
    m_width = width;
    m_hight = hight;
}


double Box::volum()const
{
    return m_length*m_width*m_hight;
}

int main()
{


    Box box1;
    box1.set_length(10);
    box1.set_width(10);
    box1.set_hight(10);

    Box box2(10,10,5);
    std::cout << "the volume of the box1 = "<< box1.volum() << std::endl;
    std::cout << "the volume of the box2 = "<< box2.volum() << std::endl;

    return 0;
}
