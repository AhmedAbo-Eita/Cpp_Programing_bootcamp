#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

void print_guest_list(const string &guest_1,const string &guest_2,const string &guest_3);//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
void clear_guest_list( string &guest_1,string &guest_2,string &guest_3);//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES

int main()
{
    string guest_1 {"Larry"};
    string guest_2 {"Moe"};
    string guest_3 {"Curly"};

    print_guest_list(guest_1,guest_2,guest_3);
    clear_guest_list(guest_1,guest_2,guest_3);
    print_guest_list(guest_1,guest_2,guest_3);


    return 0;
}

/**
 * @brief      Prints the guest list
 *
 * @param[in]  guest_1  The first guest
 * @param[in]  guest_2  The second guest
 * @param[in]  guest_3  The third guest
 */

void print_guest_list(const string &guest_1,const string &guest_2,const string &guest_3)
{
    cout << guest_1 << endl;
    cout << guest_2 << endl;
    cout << guest_3 << endl;

}

void clear_guest_list( string &guest_1,string &guest_2,string &guest_3)
{
    guest_1 = " ";
    guest_2 = " ";
    guest_3 = " ";
}
