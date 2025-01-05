#include <iostream>

using namespace std;

void swapPointers(int* ptr1, int* ptr2);
/**
 * @brief      Main function
 *
 * @details    This program swaps the values of two integer variables using pointers and a swap function.
 *
 * @return     0
 **/
int main(){
    int num1  {5};
    int num2  {10};

    // printing the values before swapping
    cout << "----------before swapping------------"<< endl;
    cout << "num1 = "<< num1 << endl;
    cout << "num2 = "<< num2 << endl; 

    // declare pointers to swap vlaues using swap function 
    int *ptr_num1 {&num1};
    int *ptr_num2 {&num2};

    // calling the function 
    swapPointers(ptr_num1,ptr_num2);
    cout << "----------After swapping------------"<< endl;
    cout << "num1 = "<< num1 << endl;
    cout << "num2 = "<< num2 << endl; 


    return 0;
}

/**
 * @brief      Swaps the values of two integer variables using pointers.
 *
 * @details    This function takes two pointers to int variables and swaps their values without using a temporary variable.
 *
 * @param[in]  ptr1  Pointer to the first integer variable.
 * @param[in]  ptr2  Pointer to the second integer variable.
 **/
void swapPointers(int* ptr1, int* ptr2) {
    
    // swaping the values without using temp variable
    *ptr1 = *ptr1 + *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;
    
}