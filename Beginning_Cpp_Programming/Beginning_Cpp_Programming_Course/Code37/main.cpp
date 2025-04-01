#include <iostream>
using namespace std;


/**
 * @brief      Finds the maximum element in an array of integers.
 *
 * @details    This function loops through an array of integers and returns the
 *             maximum element in the array.
 *
 * @param[in]  arr   The array of integers to search.
 * @param[in]  size  The number of elements in the array.
 *
 * @return     The maximum element in the array.
 */
int find_max_element(int* arr, int size)
{
    int counter {0};
    int max = *arr;
    for(counter = 1 ; counter < size ; counter ++)
    {
        if (max < *(arr+counter))
        {
            max = *(arr+counter);
        }

    }
    return max;
}
int main()
{
    int arr[] = {12, 45, 67, 23, 9};
    int size  = sizeof(arr)/sizeof(arr[0]);

    cout<< "the max value in array = " << find_max_element(arr,size);

    return 0;
}