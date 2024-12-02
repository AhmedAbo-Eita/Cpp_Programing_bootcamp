/************************************ 
*auther: Ahmed Aboeita
*date: 9/11/2024
*In this exercise, you will write a statement using cout  
*and the insertion operator <<  to display how many dogs 
*Sally has.  
**************************************/

#include <iostream>
using namespace std;

void sallys_dogs() {
    
    int x {3};
    
    //print the how many dogs sally has
    cout << "Sally has " << x << " dogs.";

}

int main(){
    //calling the function 
    sallys_dogs();
    return 0;
}