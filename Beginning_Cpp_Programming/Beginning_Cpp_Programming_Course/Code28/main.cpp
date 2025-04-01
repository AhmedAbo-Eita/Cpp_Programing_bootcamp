#include <iostream>
#include <cmath>
using namespace std;

// decleration prototypes of functions

double fahrenheit_to_celsius (double fahrenheit_temperature);
double fahrenheit_to_kelvin (double fahrenheit_temperature);


int main() {
    double F_temperature {};

    cout << "Enter the temperature in fahrenhit: ";
    cin >> F_temperature; 

    cout << "---------------------------------------"<<endl;

    cout << "Temperature in Celsius: " << fahrenheit_to_celsius(F_temperature) << endl;
    cout << "Temperature in kelvin: " << fahrenheit_to_kelvin(F_temperature) << endl;

    return 0;
}

/**
 * @brief      Converts a temperature in Fahrenheit to Celsius.
 *
 * @details    This function takes a temperature in Fahrenheit, and returns the
 *             equivalent temperature in Celsius. The conversion is done using the
 *             formula: (5.0/9.0)*(fahrenheit_temperature - 32). The result is
 *             rounded to the nearest integer using the round() function from the
 *             cmath library.
 *
 * @param[in]  fahrenheit_temperature  The temperature to convert, in Fahrenheit.
 *
 * @return     The equivalent temperature in Celsius, as a double.
 */
double fahrenheit_to_celsius (double fahrenheit_temperature)
{
    return round((5.0/9.0)*(fahrenheit_temperature - 32));
}


/**
 * @brief      Converts a temperature in Fahrenheit to Kelvin.
 *
 * @details    This function takes a temperature in Fahrenheit, and returns the
 *             equivalent temperature in Kelvin. The conversion is done using the
 *             formula: (5.0/9.0)*(fahrenheit_temperature - 32) + 273. The result
 *             is rounded to the nearest integer using the round() function from
 *             the cmath library.
 *
 * @param[in]  fahrenheit_temperature  The temperature to convert, in Fahrenheit.
 *
 * @return     The equivalent temperature in Kelvin, as a double.
 */
double fahrenheit_to_kelvin (double fahrenheit_temperature)
{
    return round((5.0/9.0)*(fahrenheit_temperature- 32) + 273);
}