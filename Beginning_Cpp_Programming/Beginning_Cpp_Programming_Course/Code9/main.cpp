/*  Section 7
    Challenge - Solution
    
    Write a C++ program as follows:
    
    Declare 2 empty vectors of integers named
    vector1 and vector2, respectively.
    
    Add 10 and 20 to vector1 dynamically using push_back
    Display the elements in vector1 using the at() method as well as its size using the size() method
    
    Add 100 and 200 to vector2 dynamically using push_back
    Display the elements in vector2 using the at() method as well as its size using the size() method

    Declare an empty 2D vector called vector_2d
    Remember, that a 2D vector is a vector of vector<int>
    
    Add vector1 to vector_2d dynamically using push_back
    Add vector2 to vector_2d dynamically using push_back
    
    Display the elements in vector_2d using the at() method
    
    Change vector1.at(0) to 1000
    
    Display the elements in vector_2d again using the at() method
    
    Display the elements in vector1 
    
    What did you expect? Did you get what you expected? What do you think happended?
*/
// practise with vectors 

#include <iostream>
#include <vector>

using namespace std;



/**
 * @brief      Main function
 *
 * @details    This program is a demonstration of how to use vectors in C++.
 *             It shows how to add elements to a vector dynamically using the
 *             push_back() method, how to get the size of a vector using the
 *             size() method, how to access elements in a vector using the at()
 *             method, and how to use a two dimensional vector.
 *
 * @return     0
 **/
int main(){

    vector <int> vector1;
    vector <int> vector2;

    //adding values to vector 1
    vector1.push_back(10);
    vector1.push_back(20);

    
    int counter =0;

    //print vectors
    int size1 = vector1.size();
    int size2 = vector2.size();
    cout<< "Vector1 : " << endl;
    for(counter=0; counter<size1 ; counter++){
        cout << vector1.at(counter)<<endl; 
    } 
    cout<< "Vector2 : " << endl;
    for(counter=0; counter<size2 ; counter++){
        cout << vector2.at(counter)<<endl; 
    } 

    //adding values to vector 2
    vector2.push_back(100);
    vector2.push_back(200);

    //print vectors
    size1 = vector1.size();
    size2 = vector2.size();
    cout<< "Vector1 : " << endl;
    for(counter=0; counter<size1 ; counter++){
        cout << vector1.at(counter)<<endl; 
    } 
    cout<< "Vector2 : " << endl;
    for(counter=0; counter<size2 ; counter++){
        cout << vector2.at(counter)<<endl; 
    } 

    // two dimentional vector
    vector <vector<int>> vector2d;
    vector2d.push_back(vector1);
    vector2d.push_back(vector2);

    int counter2=0;
    int sized = vector2d.size();
    cout<< "Vector2d : " << endl;
    for(counter=0; counter<sized ; counter++){
        for(counter2=0; counter2 < size1;counter2++){
            cout << vector2d.at(counter).at(counter2)<<endl; 
        } 
    } 

    //Change vector1.at(0) to 1000
    vector1.at(0) = 1000;

    cout<< "Vector2d : " << endl;
    for(counter=0; counter<sized ; counter++){
        for(counter2=0; counter2 < size1;counter2++){
            cout << vector2d.at(counter).at(counter2)<<endl; 
        } 
    } 
    //print vectors
    size1 = vector1.size();
    cout<< "Vector1 : " << endl;
    for(counter=0; counter<size1 ; counter++){
        cout << vector1.at(counter)<<endl; 
    } 
   

    return 0;
}