#include <iostream>
#include <string>
#include <typeinfo>  // 使用 `typeid` 需要包含的头文件

using namespace std;

class Equipment {

private:
    string type;
    string name;

public:
    Equipment(string type, string name): type(type), name(name){}

    virtual ~Equipment(){}

    void show() {
        cout << "Equipment type: " << type << endl;
        cout << "Equipment name: " << name << endl;
    }

    string get_name() {
        return name;
    }
};

class Weapon: public Equipment {

private:
    int attack_power;

public:
    Weapon(string name, int attack_power): Equipment("Weapon", name), attack_power(attack_power){}


    ~Weapon() override {}

    void use() {
        cout << "Attack with power: " << attack_power << endl;
    }
};

class Armour: public Equipment {

private:
    int defense_level;

public:
    Armour(string name, int defense_level): Equipment("Armour", name), defense_level(defense_level){}

    ~Armour() override {}

    void use() {
        cout << "Defend with volume: " << defense_level << endl;
    }
};

class Warrior {

private:
    Weapon* weapon;
    Armour* armour;

public:
    Warrior(): weapon(nullptr), armour(nullptr){}

    ~Warrior() {

        if (weapon != nullptr)
            cout << "Unequip " << weapon->get_name() << endl;

        delete weapon;

        if (armour != nullptr)
            cout << "Unequip " << armour->get_name() << endl;

        delete armour;
    }

    void add_equipment(Equipment* eq) {

        if (typeid(*eq) == typeid(Weapon)) {
            this->weapon = (Weapon*) eq;
            cout << "Equip " << eq->get_name() << endl;
        }


        if (typeid(*eq) == typeid(Armour)) {
            this->armour = (Armour*) eq;
            cout << "Equip " << eq->get_name() << endl;
        }

    }

    void attack() {

        if (weapon == nullptr)
            cout << "No weapon yet!";
        else
            weapon->use();
    }
};

int main() {

    Warrior* yzh = new Warrior();

    Weapon* liquid_sword = new Weapon("Liquid Sword", 500);
    Armour* superman_suit = new Armour("Superman Suit", 100);

    yzh->add_equipment(liquid_sword);
    yzh->add_equipment(superman_suit);

    yzh->attack();

    delete yzh;

    return 0;
}