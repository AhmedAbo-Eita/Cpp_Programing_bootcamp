#include <QCoreApplication>
#include <QDebug>
#include "house.h"


void do_stuff()
{
    //stack memory
    House h1 (nullptr,"First");
    h1.print_info();


    //heap memory
    House* p_h1 = new House(nullptr,"Second");
    p_h1->print_info();
    delete p_h1;

}
int main()
{
    do_stuff(); // calling function

    qDebug() << "Done!";

    return 0;
}
