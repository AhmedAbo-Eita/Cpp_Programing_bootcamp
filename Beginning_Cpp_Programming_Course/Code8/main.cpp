#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector <int> vec {10,20,30,40,50};
    vec.at(0) = 100;
    vec.at(4) = 1000;

    int counter = 0;
    for(counter=0;counter<5; counter++){

        cout << "Element number " << counter+1 << " is "<< vec.at(counter) << endl;
    }


    return 0;
}