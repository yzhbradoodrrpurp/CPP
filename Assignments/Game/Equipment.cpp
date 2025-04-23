//
// Created by 易治行 on 2025/4/23.
//

#include "Character.h"
#include "Equipment.h"
#include <iostream>

Equipment::Equipment(Type type, Character* owner, int value): type(type), owner(owner), value(value) {}

Equipment::~Equipment() {
    delete owner;
}

Equipment::Type Equipment::get_type() {
    return type;
}

Character* Equipment::get_owner() {
    return owner;
}

std::ostream& operator<<(std::ostream& cout, Equipment* eq) {


    return cout;
}


LiquidSword::LiquidSword(): Equipment(attack, new Warrior(), 40){}
LiquidSword::~LiquidSword(){}

AK47::AK47():Equipment(defense, new Wizard(), 30){}
AK47::~AK47(){}

