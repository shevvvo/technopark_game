//
// Created by ilyas on 14.11.2021.
//

#ifndef CHAINOFRESPONSABILITY_OBJECT_H
#define CHAINOFRESPONSABILITY_OBJECT_H

class Object {
public:
    virtual bool Damagable() const = 0;
    virtual unsigned char Damage(const unsigned char damageValue) = 0;
    virtual bool Respawn() = 0;
    virtual bool CanBeStandOn() const { return true; };
    virtual void ToDo(Object *player) = 0;
    virtual char getObjectSymbol() = 0;
    virtual unsigned int getX() = 0;
    virtual unsigned int getY() = 0;
    virtual void setXY(unsigned int x, unsigned int y) = 0;
};

class AbstractObject : public Object {
public:
    unsigned char Damage(const unsigned char damageValue) override {
        return 1;                               // Если умер - возвращает true
    }
    bool Respawn() override {
        return false;
    }
    virtual bool CanBeStandOn() const { return true; };
    void ToDo(Object *player) override {}
    char getObjectSymbol() override {
        return '0';
    }

    unsigned int getX() override { return x; }
    unsigned int getY() override { return y; }
    void setXY(unsigned int rX, unsigned int rY) override {
        x = rX;
        y = rY;
    }
    ~AbstractObject() = default;

private:
    unsigned int x;
    unsigned int y;
};

#endif //CHAINOFRESPONSABILITY_OBJECT_H
