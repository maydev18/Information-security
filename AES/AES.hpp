#pragma once
#include <string>
#include <array>
using byte = uint8_t;
using block = std :: array<std :: array<byte , 4> , 4>;

class AES{

private:
    block keys[11];
    static const std::array<std::array <byte , 16> , 16> sbox;
    static const std::array<std::array <byte , 16> , 16> inv_sbox;
    static const std::array<byte , 11> rcon;
    static const block mix_col_matrix;
    static const block inv_mix_col_matrix;
    byte xtime(byte a);
    byte gmul(byte a , byte b);
    byte get_byte(char ch);
    char get_char(byte b);
    byte get_sbox_byte(byte b , bool inverse);
    void print_block(const block & b);
    block sub_bytes(const block & b);
    block shift_rows(const block & b);
    block mix_columns(const block & b);
    block add_round_key(const block & b , int round);
    void generate_round_keys(const std::string &key);
    block string_to_state(const std::string & s);
    std::string state_to_string(const block &b);
    block inv_shift_rows(block &b);
    block inv_mix_columns(block &b);
    block inv_sub_bytes(block &b);

public:
    std::string encrypt(const std::string &data , const std::string &key);
    std::string decrypt(const std::string &encrypted_data);
};
