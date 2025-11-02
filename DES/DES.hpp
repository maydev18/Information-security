#pragma once
#include <string>
#include <array>
class DES{

private:
    uint64_t initial_permutation(uint64_t data);
    uint64_t final_permutation(uint64_t data);
    uint64_t performRound(uint64_t data , bool e);
    uint64_t f(uint64_t data , uint64_t roundKey);
    uint64_t leftRotate(uint64_t k);
    uint64_t applyPC1(uint64_t key);
    uint64_t applyPC2(uint64_t key);
    void generateRoundKeys(uint64_t k);
    uint64_t expansionPBox(uint64_t ri);
    uint64_t apply_sbox(uint64_t ri);
    uint64_t apply_straight_Pbox(uint64_t ri);
    const static uint32_t initialPermutation[64];
    const static uint32_t finalPermutation[64];
    const static uint32_t PC1[56];
    const static uint32_t PC2[48];
    const static uint32_t E[48];
    const static uint32_t S_BOX[8][4][16];
    const static uint32_t StraightPbox[32];
    
    static uint64_t roundKeys[16];

public:
    std::uint64_t encrypt(uint64_t data , uint64_t key);
    std::uint64_t decrypt(uint64_t encrypted_data);
};
