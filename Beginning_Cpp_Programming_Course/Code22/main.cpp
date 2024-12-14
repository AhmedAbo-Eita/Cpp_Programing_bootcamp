#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program is a demonstration of nested for loops.
 *             It takes a vector of integers as input and multiplies each element
 *             with all the elements that are after it in the vector and sums
 *             up all the results.
 *
 * @return     0
 **/
int main(){

    vector <int> vec {2,4,6,8};
    unsigned int index {};
    unsigned int index2 {};
    int result {};
    for (index = 0 ; index < vec.size() ; index++ )
    {
        for (index2 = index+1 ; index2 < vec.size() ; index2++ )
        {
            result = result + vec.at(index)*vec.at(index2);
        }
    }

    cout <<"The result is : " << result << endl;

    return 0;
}