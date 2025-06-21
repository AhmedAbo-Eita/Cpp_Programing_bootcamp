#ifndef COMPONENT_H
#define COMPONENT_H
#include <QString>

class Component
{
public:
    //construtor
    Component();

    // Comparison operator
    bool operator==(const Component& other) const;

    // distractor
    ~Component();

    //set class member attributes
    void setMPN(QString MPN);
    void setQuantity(int quantity);
    void setFootpint(QString footprint);
    void setType(QString type);
    void setLocation(QString location);

    //get classmember attributes
    QString getMPN();
    int     getQuantity();
    QString getFootprint();
    QString getType();
    QString getLocation();


private:
    QString m_MPN;
    int m_quantity {0};
    QString m_footprint;
    QString m_type;
    QString m_location;
};

#endif // COMPONENT_H
