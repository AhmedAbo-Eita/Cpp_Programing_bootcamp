#include <QCoreApplication>
#include <QDebug>
//#include <memory>
#include "house.h"



void do_stuff ()
{
    //parent
    //House* p_parent = new House(nullptr, "Parent");

    std::unique_ptr<House> p_parent {new House(nullptr,"Parent")};
    //child
    House* p_house1 = new House(p_parent.get(),"House1");

    House* p_house2 = new House(p_house1,"Hosue2");

    // destranct the parent
    //delete p_parent;
}

int main()
{
    qDebug() << "Starting ... ";
    do_stuff();
    qDebug() << "Ending ... ";


    return 0;
}
