#include "../header_files/component.h"

Component::Component() {}

Component::~Component(){}

//set the class attributes
void Component::setMPN(QString MPN){ m_MPN = MPN;}
void Component::setQuantity(int quantity){m_quantity = quantity;}
void Component::setFootpint(QString footprint){m_footprint = footprint;}
void Component::setType(QString type){m_type = type;}
void Component::setLocation(QString location){m_location = location;}
void Component::setCustomercode(QString code){m_customer_code = code;}
void Component::setValue(QString value){m_value = value;}

//get the values of class attributes
QString Component::getMPN(){return m_MPN;}
int Component::getQuantity(){return m_quantity;}
QString Component::getFootprint(){return m_footprint;}
QString Component::getType(){return m_type;}
QString Component::getLocation(){return m_location;}
QString Component::getCustomerCode(){return m_customer_code;}
QString Component::getValue(){return m_value;}

// Overloads the equality operator to check if all attributes of two Component objects are identical
bool Component::operator==(const Component& other) const {
    return m_MPN == other.m_MPN &&
           m_quantity == other.m_quantity &&
           m_footprint == other.m_footprint &&
           m_type == other.m_type &&
           m_location == other.m_location &&
           m_customer_code == other.m_customer_code &&
           m_value == other.m_value;
}
