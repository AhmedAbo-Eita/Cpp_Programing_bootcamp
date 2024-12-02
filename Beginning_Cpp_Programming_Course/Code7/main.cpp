#include <iostream>

using namespace std;

int main(){
    int arr[10] {};
    arr[0] =100;
    arr[9] =1000;

    int loop_counter = 0;
    for (loop_counter=0;loop_counter<=9;loop_counter++){
        cout << arr[loop_counter]<<endl;
    }
    return 0;
}