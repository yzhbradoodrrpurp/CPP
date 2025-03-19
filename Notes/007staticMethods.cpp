//
// Created by 易治行 on 2025/3/19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {

private:
    string name;
    int salary;

public:
    Employee(string name, int salary) {
        this->name = name;
        this->salary = salary;
    }

    void display() {
        cout << "Name: " << this->name << "  Salary: " << this->salary << endl;
    }

    /*
     * NOTE: 静态方法属于整个类，而不是某个类的实例
     * 在调用静态方法时，应该以类为主体进行调用，而不是从实例调用
     */
    static int totalSalaries(vector<Employee*> employees) {
        int sum = 0;

        // NOTE: `auto` 是一个自动判断变量类型的机制
        // NOTE: 这种写法是 range-based for loop，能够直接遍历容器中的元素
        for (auto* employee:employees)
            sum += employee->salary;

        return sum;
    }
};


int main(void) {
    // NOTE: vector<...> 表示定义一个 `...` 类型的动态数组
    vector<Employee*> employees = {
        new Employee("Alice", 30000),
        new Employee("Bob", 10000),
        new Employee("Chris", 20000)
    };


    employees[0]->display();
    employees[1]->display();
    employees[2]->display();

    // NOTE: totalSalaries 是静态方法，调用它通过类而不是实例
    int sum = Employee::totalSalaries(employees);

    cout << "The total salaries are " << sum << "." <<endl;

    // 释放指针
    delete employees[2];

    int sum_ = Employee::totalSalaries(employees);

    cout << "The total salaries are " << sum_ << "." <<endl;

    return 0;
}