#include <iostream>
#include <string>

using namespace std;
string reverse_string(const string &str);
int main()
{
    string input = "Hello, World!";
    cout << input << endl ;
    cout << reverse_string(input);
  
    return 0;
}


string reverse_string(const std::string& str) {
    string reversed;
    
    const char* start = str.c_str();                    // Pointer to the first character
    const char* end = str.c_str() + str.size() - 1;     // Pointer to the last character

    while (end >= start)
    {
        reversed.push_back(*end);   // Append the character at the end pointer to the reversed string
        end--;
    }
 
    
    return reversed;
}