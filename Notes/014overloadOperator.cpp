//
// Created by 易治行 on 2025/4/16.
//

#include <iostream>
#include <string>


class Complex {

private:
    double real;
    double imag;

public:
    Complex(double real, double imag): real(real), imag(imag) {}
    Complex(): real(0), imag(0) {}

    virtual ~Complex() {}

    friend Complex operator+(const Complex &, const Complex &);
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

    // 前置 ++a
    void operator++() {
        this->x += 1;
        this->y += 1;
    }

    // 前置 --a
    void operator--() {
        this->x -= 1;
        this->y -= 1;
    }

    // 后置 a++
    void operator++(int) {
        this->x += 1;
        this->y += 1;
    }

    // 后置 a--
    void operator--(int) {
        this->x -= 1;
        this->y -= 1;
    }

    // NOTE: 重载输出操作流
    // `std::cout` 就是一个 `ostream` 类的实例
    // 必须加上引用
    std::ostream& operator<<(std::ostream cout, Point p) {
        cout << "<" << p.x << ", " << p.y << ">";
        return cout;
    }

    // NOTE: 重载下标
    int& operator[](int idx) {
        if (idx == 0)
            return x;

        if (idx == 1)
            return y;

        throw std::out_of_range("Index out of range.");
    }

    // NOTE: 重载显式类型转换
    operator std::string() {
        return "<" + std::to_string(x) + ", " + std::to_string(y) + ">";
    }

    // NOTE: 重载显式类型转换
    operator int() {
        return int(x * y);
    }

};
