#include <iostream>
#include <string>

using namespace std;

int main(){
    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};

    // get the last name only by erasing first name
    int space = journal_entry_1.find(" ");
    journal_entry_1.erase(0,space+1);

    int space2 = journal_entry_2.find(" ");
    journal_entry_2.erase(0,space2+1);

    if (journal_entry_1>journal_entry_2)
    {
        swap(journal_entry_1,journal_entry_2);
    }
    
    cout << "The first name: " << journal_entry_1 <<endl;
    cout << "The second name: " << journal_entry_2 <<endl;

    return 0;
}