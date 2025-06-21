#include "../header_files/component.h"

Component::Component() {}

Component::~Component(){}

//set the class attributes
void Component::setMPN(QString MPN){ m_MPN = MPN;}
void Component::setQuantity(int quantity){m_quantity = quantity;}
void Component::setFootpint(QString footprint){m_footprint = footprint;}
void Component::setType(QString type){m_type = type;}
void Component::setLocation(QString location){m_location = location;}

//get the values of class attributes
QString Component::getMPN(){return m_MPN;}
int Component::getQuantity(){return m_quantity;}
QString Component::getFootprint(){return m_footprint;}
QString Component::getType(){return m_type;}
QString Component::getLocation(){return m_location;}

bool Component::operator==(const Component& other) const {
    return m_MPN == other.m_MPN &&
           m_quantity == other.m_quantity &&
           m_footprint == other.m_footprint &&
           m_type == other.m_type &&
           m_location == other.m_location;
}
