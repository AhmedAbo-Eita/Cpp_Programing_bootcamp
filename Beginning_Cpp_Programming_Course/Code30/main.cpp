#include <iostream>
#include <cmath>
using namespace std;

//function prototyping 
int find_area (int side_lenght);
double find_area(double lenght , double width);

/**
 * @brief      The main function of the program.
 *
 * @details    This program tests the implementation of two overloaded functions
 *             that calculate the area of a square and a rectangle respectively.
 *             The results are printed to the console.
 *
 * @return     Returns 0 if the program runs successfully.
 */
int main(){

    //Calling the functions of calculating area of square and regtangle
    int square_area = find_area(2);
    double rectangle_area = find_area(4.5,2.3);

    //printing the result
    cout << "The area of the square is " << square_area << "\n" << "The area of the rectangle is " << rectangle_area;
    return 0;
}



/**
 * @brief      Calculates the area of a square.
 *
 * @details    This function takes the side length of a square as an input
 *             and returns the calculated area using the formula side_length * side_length.
 *
 * @param[in]  side_length  The length of a side of the square.
 *
 * @return     The area of the square as an integer.
 */

int find_area (int side_lenght){
    return side_lenght*side_lenght;
}



/**
 * @brief      Calculates the area of a rectangle.
 *
 * @details    This function takes the length and width of a rectangle as inputs
 *             and returns the calculated area using the formula length * width.
 *
 * @param[in]  lenght   The length of the rectangle.
 * @param[in]  width    The width of the rectangle.
 *
 * @return     The area of the rectangle as a double.
 */
double find_area(double lenght , double width){
    return lenght* width;
}