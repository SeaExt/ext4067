#pragma once
#include <Arduino.h>


class ext4067{
    public:
        ext4067(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3){
            _s0 = s0; _s1 = s1; _s2 = s2; _s3 = s3;
            pinMode(s1, OUTPUT); pinMode(s2, OUTPUT); pinMode(s3, OUTPUT); pinMode(s0, OUTPUT);
        }
        void setPin(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3){
            _s0 = s0; _s1 = s1; _s2 = s2; _s3 = s3;
        }
        void switchReg(uint8_t reg){
            if (reg > 15) return;
            digitalWrite(_s3, (reg & 0b1000) >> 3);
            digitalWrite(_s2, (reg & 0b0100) >> 2);
            digitalWrite(_s1, (reg & 0b0010) >> 1);
            digitalWrite(_s0, reg & 1);
        }
    private:
        uint8_t _s0, _s1, _s2, _s3;
};
