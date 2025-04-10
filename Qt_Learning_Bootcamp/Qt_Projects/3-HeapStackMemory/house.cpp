#include "house.h"
#include <QDebug>

House::House(QObject *parent, const QString &descr)
    :QObject(parent), m_descr((descr))
{
    qDebug() << "House Object Constructed";
}

void House::print_info() const
{
    qDebug() << "House: " << m_descr;
}

House::~House()
{
    qDebug() << "House Object " << m_descr << "is dying ...";
}
