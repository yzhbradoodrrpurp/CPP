//
// Created by 易治行 on 2025/4/9.
//

#include <iostream>
#include <string>


using namespace std;


class People {

public:
    enum Sex {male, female};

private:
    string name;
    Sex sex;
    int age;

public:
    People(string name, Sex sex, int age): name(name), sex(sex), age(age){}

    ~People(){}
};


// NOTE: 虚基类继承 `People`，需要重新初始化 `People`
class Teacher: virtual public People {

private:
    int salary;

public:
    Teacher(string name, Sex sex, int age, int salary): People(name, sex, age), salary(salary){}

    ~Teacher(){}
};


// NOTE: 虚基类继承 `People`，需要重新初始化 `People`
class Student: virtual public People {

private:
    int tuition;

public:
    Student(string name, Sex sex, int age, int tuition): People(name, sex, age), tuition(tuition){}

    ~Student(){}
};


// NOTE: 虚基类继承 `Teacher` 和 `Student`
class TA: virtual public Teacher, virtual public Student {

public:
    TA(string name, Sex sex, int age, int salary, int tuition): Teacher(name, sex, age, salary), Student(name, sex, age, tuition){}

    ~TA(){}
};

