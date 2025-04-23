//
// Created by 易治行 on 2025/4/23.
//

#include "Character.h"
#include "Equipment.h"

#include <iostream>
#include <typeinfo>


Character::Character(int max_blood, int attack_value, int defense_value):
        max_blood(max_blood), current_blood(max_blood), attack_value(attack_value), defense_value(defense_value) {
    attack_equipment = nullptr;
    defense_equipment = nullptr;
}

Character::~Character() {

    if (attack_equipment != nullptr)
        delete attack_equipment;

    if (defense_equipment != nullptr)
        delete defense_equipment;
}

void Character::attack(Character* ch) {
    int harm = attack_value - ch->get_defense_value();

    ch->reduce_blood(harm);

    std::cout << "Cause " << harm << " harm" << std::endl;
    std::cout << "Enemy's current blood: " << ch->get_current_blood() << std::endl;
}

void Character::reduce_blood(int harm) {
    current_blood -= harm;
}


void Character::pick_up(Equipment* eq) {
    if (typeid(eq->get_owner()) != typeid(this)) {
        std::cout << "The equipment is not for this hero." << std::endl;
        return;
    }

    if (eq->get_type() == Equipment::attack) {
        attack_equipment = eq;
        std::cout << "Pick up an attack equipment." << std::endl;
    }


    if (eq->get_type() == Equipment::defense) {
        defense_equipment = eq;
        std::cout << "Pick up an defense equipment." << std::endl;
    }


}

int Character::get_max_blood() {
    return max_blood;
}

int Character::get_current_blood() {
    return current_blood;
}

int Character::get_attack_value() {
    return attack_value;
}

int Character::get_defense_value() {
    return defense_value;
}

Equipment* Character::get_attack_equipment() {
    return attack_equipment;
}

Equipment* Character::get_defense_equipment() {
    return defense_equipment;
}

std::ostream& operator<<(std::ostream& cout, Character* ch) {

    cout << "Current Blood: " << ch->current_blood << std::endl;
    cout << "Attack Equipment: " << ch->attack_equipment << std::endl;
    cout << "Defense Equipment: " << ch->defense_equipment << std::endl;

    return cout;
}

Warrior::Warrior(): Character(500, 100, 40){}
Warrior::~Warrior(){}

Wizard::Wizard(): Character(300, 150, 20){}
Wizard::~Wizard(){}

