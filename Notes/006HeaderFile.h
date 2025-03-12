//
// Created by 易治行 on 2025/3/12.
//

// NOTE: 创建了一个头文件之后不用添加到 CMake 中，
//  直接在另一个 C++ 文件中使用 #include "....h" 调用

// NOTE: 预编译 `#ifndef`, `#define`, `#endif` ，防止重复导入相同的模块
#ifndef Circle_H
#define Circle_H

#include <iostream>

using namespace std;

const double PI = 3.141526;

class Circle {

private:
    double radius;

public:
    Circle(double radius) {
        this->radius = radius;
    }


    void setRadius(double radius) {
        this->radius = radius;
    }

    double getRadius() {
        return this->radius;
    }

    double getPerimeter() {
        return 2 * PI * this->radius;
    }

    double getArea() {
        return PI * this->radius * this->radius;
    }

    void print() {
        cout << "Radius: " << this->radius << endl;
        cout << "Perimeter: " << this->getPerimeter() << endl;
        cout << "Area: " << this->getArea() << endl;
    }

};

#endif