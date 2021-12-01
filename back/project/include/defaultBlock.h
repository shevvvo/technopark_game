//
// Created by ilyas on 16.11.2021.
//

#ifndef CHAINOFRESPONSABILITY_DEFAULTBLOCK_H
#define CHAINOFRESPONSABILITY_DEFAULTBLOCK_H

#include "Object.h"

class DefaultBlock : public AbstractObject {
    bool Damagable() const override {
        return true;
    };
    unsigned char Damage(const unsigned char damageValue) override {
        if (damageValue > health)
            return 0; // Если умер - возвращает true
        else return (health - damageValue);
    };
    bool CanBeStandOn() const override {
        return false;
    };
    char getObjectSymbol() override {
        return '4';
    }
    ~DefaultBlock() = default;
private:
    unsigned char health = 1;
};

#endif //CHAINOFRESPONSABILITY_DEFAULTBLOCK_H
