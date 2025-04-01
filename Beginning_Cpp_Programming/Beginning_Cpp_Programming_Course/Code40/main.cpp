#include <iostream>
using namespace std;

// print function to print the array using its adress and size
void print(int *arr, int size);
int *apply_all(int *arr1, int arr1_size, int *arr2 ,int arr2_size);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,array1_size);
    
    cout << "Array 2: " ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);
    cout << endl;

    // release meemory 
    delete [] results; 
    
   

    return 0;
}

/**
 * @brief Prints the elements of an integer array.
 * 
 * This function takes an integer array and its size as input and prints 
 * the elements of the array enclosed within square brackets. The elements are 
 * separated by a space.
 * 
 * @param arr Pointer to the first element of the integer array.
 * @param size Size of the integer array.
 * 
 * @return void
 */
void print(int *arr, int size)
{
    int counter {0};
    // print pracket 
    cout << "[ ";
    //print elements of array 
    for (counter = 0; counter < size; counter++)
    {
        cout << *(arr+counter) << " ";
    }
    // print close of the bracket
    cout << "]" << endl;

}
/**
 * @brief Applies the given arrays element-wise and returns a new array.
 * 
 * This function takes two integer arrays, `arr1` and `arr2`, 
 * along with their respective sizes, `arr1_size` and `arr2_size`.
 *  It multiplies each element of `arr1` with each element of `arr2`,
 *  and stores the result in a new dynamically allocated array `res`. 
 * The size of `res` is equal to the product of `arr1_size` and `arr2_size`.
 * 
 * @param arr1 Pointer to the first integer array.
 * @param arr1_size The size of the first array.
 * @param arr2 Pointer to the second integer array.
 * @param arr2_size The size of the second array.
 * @return Pointer to the newly created array containing the element-wise multiplication of `arr1` and `arr2`.
 */
int *apply_all(int *arr1, int arr1_size, int *arr2 ,int arr2_size)
{
    int *res = new int[arr1_size*arr2_size];
    // declare and initialize counters for looping 
    int counter1 {0};
    int counter2 {0};
    // declare and initialize counter for referance 
    int counter3 {0};

    // apply the main function using cascaded loops
    for(counter1=0 ; counter1<arr2_size ; counter1++)
    {
        for(counter2=0 ; counter2<arr1_size ; counter2++)
        {
            *(res+counter3) = (*(arr2+counter1)) * (*(arr1+counter2));
            counter3++;
        }
    }
    // return the addres of new array
    return res;
}
