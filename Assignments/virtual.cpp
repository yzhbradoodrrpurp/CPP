//
// Created by 易治行 on 2025/4/9.
//

#include <iostream>
#include <string>


/*
 * 虚基类用于避免菱形继承造成的不确定性
 * 虚函数用于在运行时支持多态性
 */

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

    // NOTE: 析构函数最好是虚函数
    virtual ~People(){}

    virtual void info() {
        cout << "name: " << name << endl;

        if (sex == male)
            cout << "sex: male" << endl;

        if (sex == female)
            cout << "sex: female" << endl;

        cout << "age: " << age << endl;
    }
};


// NOTE: 虚基类继承 `People`，需要显式地初始化 `People`
class Teacher: virtual public People {

private:
    int salary;

public:
    Teacher(string name, Sex sex, int age, int salary): People(name, sex, age), salary(salary){}

    ~Teacher() override {}

    void info() override {
        People::info();
        cout << "salary: " << salary << endl;
    }

    int get_salary() {
        return salary;
    }
};


// NOTE: 虚基类继承 `People`，需要显式地初始化 `People`
class Student: virtual public People {

private:
    int tuition;

public:
    Student(string name, Sex sex, int age, int tuition): People(name, sex, age), tuition(tuition){}

    ~Student() override {}

    void info() override {
        People::info();
        cout << "tuition: " << tuition << endl;
    }

    int get_tuition() {
        return tuition;
    }
};


// NOTE: 虚基类继承 `Teacher` 和 `Student`，需要显式地初始化 `People`
class TA: virtual public Teacher, virtual public Student {

public:
    TA(string name, Sex sex, int age, int salary, int tuition): People(name, sex, age), Teacher(name, sex, age, salary), Student(name, sex, age, tuition){}

    ~TA() override {}

    void info() override {
        People::info();
        cout << "salary: " << get_salary() << endl;
        cout << "tuition: " << get_tuition() << endl;
    }
};


int main(void) {

    TA* yzh = new TA("Zhihang Yi", People::male, 20, 1500, 4975);

    yzh->info();

    cout << endl;

    yzh->Teacher::info();

    cout << endl;

    yzh->Student::info();

    delete yzh;

    return 0;
}

