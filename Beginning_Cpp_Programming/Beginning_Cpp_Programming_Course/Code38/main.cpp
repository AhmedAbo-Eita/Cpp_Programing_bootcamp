#include <iostream>
using namespace std;
void reverse_array(int* arr, int size); 




int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // printing array before reversing
    cout << "Array before reversing : "; 
    for(int counter =0 ; counter<size ;counter ++)
    {
        cout << arr[counter] << " ";
    }

    cout << endl;

    // calling reverse function 
    reverse_array(arr, size);

    //printing the function after reversing
    cout << "Array After reversing : ";
    for(int counter =0 ; counter<size ;counter ++)
    {
        cout << arr[counter] << " ";
    }
    return 0;
}


/**
 * @brief      Reverses the elements of an integer array in place.
 *
 * @details    This function takes an array of integers and its size, then reverses the
 *             elements of the array in place by swapping elements from the start and end
 *             towards the center.
 *
 * @param[in]  arr   Pointer to the first element of the array to be reversed.
 * @param[in]  size  The number of elements in the array.
 */

void reverse_array(int* arr, int size) {
    int counter {0};

    for (counter = 0 ; counter < size/2 ; counter++ )
    {
        *(arr+counter) = *(arr+counter) + *(arr+size-1-counter);
        *(arr+size-1-counter) = *(arr+counter) - *(arr+size-1-counter);
        *(arr+counter)  = *(arr+counter) - *(arr+size-1-counter);
    }
}

