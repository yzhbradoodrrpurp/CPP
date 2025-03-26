//
// Created by 易治行 on 2025/3/26.
//

#include <iostream>
#include <string>


using namespace std;

enum Chromosome {XY, XX};
enum Genitals {Penis, Vagina};


class Man {

protected:
    Chromosome chromosome;
    Genitals genitals;
    string name;
    int age;

    // NOTE: 友元类，Woman 类可以访问 Man 类受保护的属性、方法
    friend class Woman;

public:
    Man(string name, int age): name(name), age(age) {
        chromosome = XY;
        genitals = Penis;
    }

};


class Woman {

protected:
    Chromosome chromosome;
    Genitals genitals;
    string name;
    int age;

    // NOTE: 友元类，Man 类可以访问 Woman 类的受保护的属性、方法
    friend class Man;

public:
    Woman(string name, int age): name(name), age(age) {
        chromosome = XX;
        genitals = Vagina;
    }

    static bool canMarry(Man a, Woman b) {
        // 由于两者是友元，所以在 Woman 类中可以访问 Man 的受保护的属性
        if (a.age < 24)
            return false;

        if (b.age < 22)
            return false;

        if (a.age < b.age)
            return false;

        return true;
    }

};


int main() {
    Man chris = Man("Chris Brown", 39);
    Woman riri = Woman("Rihanna", 39);

    bool can_marry = Woman::canMarry(chris, riri);

    cout << can_marry << endl;

    return 0;
}