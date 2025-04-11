#include <QCoreApplication>
#include <QDebug>
#include <memory.h>
#include "house.h"

void do_stuff()
{
    //unique pointer
    std::unique_ptr<House> up_house_1{new House(nullptr,"First")};
    up_house_1->print_info();


    // // shared pointer
    std::shared_ptr<House> up_house_2{new House(nullptr,"Second")};
    up_house_2->print_info();
}

int main()
{
    qDebug() << "Starting....";
    do_stuff();
    qDebug() << "Ending....";

    return 0;
}
