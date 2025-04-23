//
// Created by 易治行 on 2025/4/23.
//


#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>


class Character;


class Equipment{

public:
    enum Type {attack, defense};

private:
    Type type;
    Character* owner;
    int value;

public:
    Equipment(Type type, Character* owner, int value);

    virtual ~Equipment();

    Type get_type();

    Character* get_owner();

    friend std::ostream& operator<<(std::ostream& cout, Equipment* eq);
};


class LiquidSword: public Equipment {

public:
    LiquidSword();
    ~LiquidSword() override;

};


class AK47: public Equipment{

public:
  AK47();
  ~AK47() override;

};

#endif //EQUIPMENT_H
