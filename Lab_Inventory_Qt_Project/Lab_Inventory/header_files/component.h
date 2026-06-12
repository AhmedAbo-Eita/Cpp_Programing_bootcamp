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
    void setCustomercode(QString m_customer_code);
    void setValue(QString m_value);

    //get classmember attributes
    QString getMPN();
    int     getQuantity();
    QString getFootprint();
    QString getType();
    QString getLocation();
    QString getCustomerCode();
    QString getValue();

private:
    QString m_MPN;                          //component manifacuter part number
    int m_quantity {0};                     //component quantity
    QString m_footprint;                    //component footprint
    QString m_type;                         //component type(resistor, capacitor, IC... etc)
    QString m_location;                     //Customer number
    QString m_customer_code;                //customer referance code
    QString m_value;
};

#endif // COMPONENT_H
