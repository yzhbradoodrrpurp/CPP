//
// Created by 易治行 on 2025/4/23.
//


#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Equipment;


class Character{

private:
    int max_blood;
    int current_blood;
    int attack_value;
    int defense_value;
    Equipment* attack_equipment;
    Equipment* defense_equipment;

public:
    Character(int max_blood, int attack_value, int defense_value);

    virtual ~Character();

    virtual void attack(Character* ch);

    virtual void reduce_blood(int harm);

    virtual void pick_up(Equipment* eq);

    virtual int get_max_blood();

    virtual int get_current_blood();

    virtual int get_attack_value();

    virtual int get_defense_value();

    virtual Equipment* get_attack_equipment();

    virtual Equipment* get_defense_equipment();

    friend std::ostream& operator<<(std::ostream& cout, Character* ch);

};


class Warrior: public Character{

public:
  Warrior();
  ~Warrior() override;

};


class Wizard: public Character{

public:
  Wizard();
  ~Wizard() override;

};

#endif //CHARACTER_H
