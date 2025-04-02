//
// Created by 易治行 on 2025/4/2.
//

#include <string>

using namespace std;

class People {

public:
    enum Sex {male, female};

private:
    string name;
    int age;
    Sex sex;

public:
    People(string name, int age, Sex sex): name(name), age(age), sex(sex){}


};

class Student: public People {

private:
    string id;

public:
    Student(string name, int age, Sex sex, string id): People(name, age, sex), id(id) {}

};