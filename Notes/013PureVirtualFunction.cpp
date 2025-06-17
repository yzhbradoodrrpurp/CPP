//
// Created by 易治行 on 2025/4/16.
//

#include <iostream>

/*
 * 抽象类是具有纯虚函数的类
 * 抽象类不能被实例化，即不能用来创建对象
 */

class Graphic {

public:
    enum Type {Triangle, Rectangle};

private:
    double square;

public:
    Graphic(double square): square(square){}

    virtual ~Graphic(){}

    // NOTE: 纯虚函数，在母类中定义一个函数但是不实现，完全交给子类实现 (强制)
    virtual void print_type() = 0;
};


class Triangle: public Graphic {

private:
    Type type;

public:
    Triangle(double square): Graphic(square), type(Type::Triangle) {}

    ~Triangle() override {}

    void print_type() override {
        std::cout << type << std::endl;
    }
};


class Rectangle: public Graphic {

private:
    Type type;

public:
    Rectangle(double square): Graphic(square), type(Type::Rectangle){}

    ~Rectangle() override {}

    void print_type() override {
        std::cout << type << std::endl;
    }
};