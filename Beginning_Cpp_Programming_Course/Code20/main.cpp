#include <iostream>
#include <vector>
using namespace std;

int main(){
    int count = 0;
    vector <int> vec = {10,20,30,40,50,-99,70,80,90,100};
    unsigned int i = 0;
   while (vec[i]!=-99 && i<vec.size())
   {
        count++;
        i++;
   }

    cout << "The count = " << (count+1) << endl;

    return 0;
}