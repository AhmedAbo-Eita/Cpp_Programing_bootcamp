#include <iostream>
#include <string>

using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program is a simple and very old method of sending secret messages.
 *             It uses a substitution cipher to encrypt and decrypt a message given by the user.
 *
 * @return     0
 **/
int main() {
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    // Get the message from the user
    string message{};
    cout << "Enter your message: ";
    getline(cin,message);

    
    string encrypted_message{};
    size_t index {};
    size_t f_index {};

    // Encrypt the message
    for(index = 0 ; index < message.length(); index++)
    {
        f_index = alphabet.find(message.at(index));
     
        if (f_index != string::npos )
        { 
            encrypted_message += key.at(f_index);
        }
        else
        {
            encrypted_message += message.at(index);
        }
        
    }

    // Print the encrypted message
    cout << "---------------------------------" << endl;
    cout << "encrypted message : " << encrypted_message << endl;

    
    // Decrypt the message
    string new_message {};
    for(index = 0 ; index < encrypted_message.length(); index++)
    {
        f_index = key.find(encrypted_message.at(index));
     
        if (f_index != string::npos )
        { 
            new_message += alphabet.at(f_index);
        }
        else
        {
            new_message += encrypted_message.at(index);
        }
        
    }

    // Print the decrypted message
    cout << "---------------------------------" << endl;
    cout << "message : " << message;

    cout << endl;
    return 0;
}

