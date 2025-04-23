//
// Created by 易治行 on 2025/4/23.
//

#include "Character.h"
#include "Equipment.h"
#include <iostream>

int main(void) {

    Character* ian = new Warrior();
    Character* bella = new Wizard();

    Equipment* sword = new LiquidSword();
    Equipment* gun = new AK47();

    ian->pick_up(sword);
    bella->pick_up(gun);

    ian->attack(bella);
    bella->attack(ian);

    std::cout << ian;
    std::cout << bella;

    delete ian;
    delete bella;

    return 0;
}