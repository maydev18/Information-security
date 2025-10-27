#include "AES.hpp"
#include <iostream>
int main(){
    AES a;
    std::string k = "2b7e151628aed2a6abf7158809cf4f3c";
    std::string data = "3243f6a8885a308d313198a2e0370734";
    std::string encrypted_data =  a.encrypt(data , k);
    std :: string decrypted_data = a.decrypt(encrypted_data);
    std :: cout << "Encrypted data : " << encrypted_data << "\nDecrypted Data : " << decrypted_data << '\n';
    return 0;
}
