#include <iostream>

/*
 *
 * Rectangle class
 *
 */

class Rectangle{

public:
    Rectangle();
    Rectangle(int width,int hight);
    //methods of class
    void set_width(int width);
    void set_hight(int hight);
    double get_area()const;
    //attributes
private:
    double m_width {};
    double m_hight {};
};
    // Rectangle Class implementation
void Rectangle::set_width(int width)
{
    m_width = width;
}
void Rectangle::set_hight(int hight)
{
    m_hight = hight;
}
double Rectangle::get_area()const
{
    return m_width*m_hight;
}

Rectangle::Rectangle(){}
Rectangle::Rectangle(int width,int hight)
{
    m_width = width;
    m_hight = hight;
}

/*
 *
 * box class
 *
 */

class  Box{
public:
    //constructors
    Box();
   // Box(Rectangle rectangle,double length);
    Box(double length, double width, double hight);


    //class methods
    void set_length(double length);
    void set_hight(double hight);
    void set_width(double width);
    double volume()const;


    //class attributes
private:
    Rectangle m_rectangle;
    double m_length;

};

//impelementation
void Box::set_length(double length)
{
    m_length = length;
}

void Box::set_hight( double hight)
{
    m_rectangle.set_hight(hight);
}
void Box::set_width( double width)
{
    m_rectangle.set_width(width);
}

double Box::volume()const
{
    return m_length*m_rectangle.get_area();
}

//Constructor impelementation
Box::Box()
{
    std::cout << "No parameter constructor called" << std::endl;
};
Box::Box(double length, double width, double hight):m_rectangle(width,hight),m_length(length)
{
    std::cout << "two parameter constructor called" << std::endl;
}


int main()
{
    Rectangle rec1(10,10);
    Box box1(10.0,20.0,30.0);
    std::cout << "the area of the rec1 = "<< rec1.get_area() << std::endl;
    std::cout << "the volume of the box1 = "<< box1.volume() << std::endl;

    return 0;
}
