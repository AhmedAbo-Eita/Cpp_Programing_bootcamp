#ifndef __DOG__H__
#define __DOG__H__

#include <string>
using namespace std;

class Dog {
private:
    string name;
    int age;
public:
string get_name(){return name;}
void set_name(string p_name){name = p_name;}
int get_age(){return age;}
void set_age(int p_age){age = p_age;}
/************************************************** */
int get_human_years(){return age*7;}
string speak(){return "Woof";}
/************************************************** */
Dog()
{
    name = "None";
    age = 0;
}

Dog(string name_val, int age_val)
{
    name = name_val;
    age = age_val;
}


};



#endif