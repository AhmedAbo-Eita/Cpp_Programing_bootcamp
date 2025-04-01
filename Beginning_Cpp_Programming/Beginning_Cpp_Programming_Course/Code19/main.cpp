#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program takes a given vector of integers as input and counts the number of 
 *             elements that are divisible by either 3 or 5.
 *
 * @return     0
 **/
int main()
{
    // Given Vector 
    vector<int> vec {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700};
    // counter of element
    int count{0};

    for (auto element :vec)
    {
        if (element % 3 == 0 || element % 5 == 0)
        {
            count++;
        }
    }

    cout << "Number of elements = " << count; 
    return 0;
}