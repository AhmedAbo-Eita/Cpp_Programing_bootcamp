#include <iostream>

using namespace std;

void multiply_with_pointer(int* ptr, int multiplier);



int main() 
{   int num         {10};
    int *ptr_num    {&num};
    int mult        {22};
    
    multiply_with_pointer(ptr_num,mult);

    cout << "The Vlaue = " << num; 

    return 0;
}


void multiply_with_pointer(int* ptr, int multiplier)
{
    *ptr *=  multiplier;
}