#pragma once
#include <Arduino.h>

const uint8_t EXT4067_COMANDS[16]{
    0b0000, // 00
    0b1000, // 01
    0b0100, // 02
    0b1100, // 03
    0b0010, // 04
    0b1010, // 05
    0b0110, // 06
    0b1110, // 07
    0b0001, // 08
    0b1001, // 09
    0b0101, // 10
    0b1101, // 11
    0b0011, // 12
    0b1011, // 13
    0b0111, // 14
    0b1111  // 15
};

class ext4067{
    public:
        ext4067(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3){
            _s0 = s0; _s1 = s1; _s2 = s2; _s3 = s3;
            pinMode(s1, OUTPUT); pinMode(s2, OUTPUT); pinMode(s3, OUTPUT); pinMode(s0, OUTPUT);
        }
        
        void switchReg(uint8_t reg){
            if (reg > 15) return;
            write4(EXT4067_COMANDS[reg]);
        }
    private:
        uint8_t _s0, _s1, _s2, _s3;
        void write4(uint8_t val){
            // 0 - 0 - 0 - 0 - _s0 - _s1 - _s2 - _s3
            digitalWrite(_s0, (bool) val & 0b1000);
            digitalWrite(_s1, (bool) val & 0b0100);
            digitalWrite(_s2, (bool) val & 0b0010);
            digitalWrite(_s3,        val & 0b0001);
        }
};
