#include "DES.hpp"
#include <iostream>
int main(){
    DES a;
    uint64_t input = 0x0123456789ABCDEF;
    uint64_t key = 0x133457799BBCDFF1;
    uint64_t encrypted_data = a.encrypt(input , key);
    uint64_t decrypted_data = a.decrypt(encrypted_data);
    std :: cout << std :: hex  << encrypted_data << "\n";
    std :: cout << std :: hex  << decrypted_data << "\n";
    if(decrypted_data == input){
        std :: cout << "DES is working fine";
    }
    else{
        std :: cout << "DES failed";
    }
    return 0;
}
