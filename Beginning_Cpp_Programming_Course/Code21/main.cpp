#include <iostream>
#include <vector>


using namespace std;

int main(){
    vector <char> vec {'f','r','a','n','k'};
    unsigned int index {0};


    do{
        if (vec.at(index) == 'a' || vec.at(index) == 'e' || vec.at(index) == 'i' || vec.at(index) == 'o' || vec.at(index) == 'u')
        {
            cout << "Vowel found: " << vec.at(index);
        }
        if(index == vec.size() && vec.at(index) !='a' || vec.at(index) != 'e' || vec.at(index) != 'i' || vec.at(index) != 'o' || vec.at(index) != 'u' )
        {
            cout << "No vowel was found";
        }
        index++;

    }while(vec.at(index) !='a' || vec.at(index) != 'e' || vec.at(index) != 'i' || vec.at(index) != 'o' || vec.at(index) != 'u');


    return 0;
}
