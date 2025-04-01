#include <iostream>

class Rectangle{
    //methods of class
public:
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

int main()
{
    Rectangle r;
    r.set_hight(5.0);
    r.set_width(10.0);

    std::cout << "The area of rectanglr = " << r.get_area()<<std::endl;

    return 0;
}
