//
// Created by 易治行 on 2025/4/23.
//

#include <string>

using namespace std;

class Person {

public:
    enum Sex {male, female};

private:
    string name;
    Sex sex;
    int age;

public:
    Person(string name, Sex sex, int age): name(name), sex(sex), age(age) {}

    Person(Person& p) {
        name = p.get_name();
        sex = p.get_sex();
        age = p.get_age();
    }

    ~Person() {}

    string get_name() {
        return name;
    }

    Sex get_sex() {
        return sex;
    }

    int get_age() {
        return age;
    }
};