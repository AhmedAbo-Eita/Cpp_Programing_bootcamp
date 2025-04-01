#include <iostream>

class Regtangle{
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
 // Regtangle Class implementation
void Regtangle::set_width(int width)
{
    m_width = width;
}
void Regtangle::set_hight(int hight)
{
    m_hight = hight;
}
double Regtangle::get_area()const
{
    return m_width*m_hight;
}

int main()
{
    Regtangle r;
    r.set_hight(5.0);
    r.set_width(10.0);

    std::cout << "The area of regtanglr = " << r.get_area()<<std::endl;

    return 0;
}
