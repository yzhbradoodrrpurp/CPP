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
    Sex sex;
    int age;

public:
    // NOTE: `explicit` 的作用是防止隐式调用构造函数
    explicit People(string name, Sex sex, int age): name(name), sex(sex), age(age){}

};

/*
 * NOTE: 有 `public`, `protected`, `private` 三种继承方式
 * `public`: 从母类继承的属性和方法 `public` 和 `protected` 不改变，`private` 不能访问
 * `protected`: 从母类继承的属性和方法 `public` 和 `protected` 全部变成 `protected`，`private` 不能访问
 * `private`: 从母类继承的属性和方法 `public` 和 `protected` 全部变成 `private`，`private` 不能访问
 */

class Student: public People {

private:
    string id;

public:
    explicit Student(string name, Sex sex, int age, string id): People(name, sex, age), id(id) {}

};