#pragma once
#include <string>
#include <array>
using byte = uint64_t;

class DES{

private:
    

public:
    std::string encrypt(byte data , byte key);
    std::string decrypt(byte encrypted_data);
};
