#include <iostream>
#include <string>
using namespace std;

void print_guest_list(string guest_list[],size_t guest_list_size);//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
void clear_guest_list(string guest_list[],size_t guest_list_size);//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
                                      
int main()
{
    // input the guest list
    string guest_list[] {"Larry", "Moe", "Curly"};
    // input the guest list size
    size_t guest_list_size {3};

    print_guest_list(guest_list,guest_list_size);
    clear_guest_list(guest_list,guest_list_size);
    print_guest_list(guest_list,guest_list_size);


    
    return 0;
}

/**
 * @brief      Prints the elements in the guest_list array.
 *
 * @param[in]  guest_list  The list of guest names
 * @param[in]  guest_list_size  The number of elements in the guest_list array
 *
 * @details    This function prints the elements in the guest_list array to the
 *             console, one element per line.
 */
void print_guest_list(string guest_list[],size_t guest_list_size)
{
    size_t counter;
    for (counter=0;counter<guest_list_size;counter++)
    {
        cout << guest_list[counter]<<endl; 
    }
}

/**
 * @brief      Clears the elements in the guest_list array.
 *
 * @param[in,out]  guest_list  The list of guest names
 * @param[in]  guest_list_size  The number of elements in the guest_list array
 *
 * @details    This function loops through the guest_list array and sets each
 *             element to a single space (" ").
 */
void clear_guest_list(string guest_list[],size_t guest_list_size)
{
    size_t counter;
    for (counter=0;counter<guest_list_size;counter++)
    {
        guest_list[counter] = " "; 
    }
}