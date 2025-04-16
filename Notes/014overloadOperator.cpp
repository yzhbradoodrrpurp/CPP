//
// Created by 易治行 on 2025/4/16.
//

#include <string>
#include <string.h>

class Complex {

private:
    double real;
    double imag;

public:
    Complex(double real, double imag): real(real), imag(imag) {}
    Complex(): real(0), imag(0) {}

    virtual ~Complex() {}

    friend Complex operator+(const Complex &self, const Complex &other);
};

// NOTE: 使用友元函数的方式重载运算符函数
Complex operator+(const Complex &self, const Complex &other) {
    double real = self.real + other.real;
    double imag = self.imag + other.imag;

    return Complex(real, imag);
}


class Point {

private:
    int x;
    int y;

public:
    Point(int x, int y): x(x), y(y){}

    ~Point(){}

    // NOTE: 在类内直接重载运算符函数
    Point operator+(const Point &other) {
        return Point(this->x + other.x, this->y + other.y);
    }

    // NOTE: 在类内直接重载运算符函数
    Point operator-(const Point &other) {
        return Point(this->x - other.x, this->y - other.y);
    }
};
