//
// Created by 易治行 on 2025/6/4.
//

#include<iostream>
#include<string>

class ShapeFactory;
class Composite;

class Shape {

private:
    int x, y;
public:
    Shape(int x, int y): x(x), y(y){}
    virtual ~Shape(){}
    virtual void draw(){};
    friend Composite;
    friend ShapeFactory;
};


class Circle: public Shape {
    static std::string name;

public:
    Circle(int x, int y): Shape(x, y){}
    ~Circle() override {}
    void draw() override {
        std::cout << "circle" << std::endl;
    }

    friend ShapeFactory;
};


class Rectangle: public Shape {
    static std::string name;

public:
    Rectangle(int x, int y): Shape(x, y){}
    ~Rectangle() override {}

    void draw() override {
        std::cout << "rectangle" << std::endl;
    }

    friend ShapeFactory;
};

std::string Circle::name = "circle";
std::string Rectangle::name = "rectangle";

class ShapeFactory {

public:
    static std::unique_ptr<Shape> create(std::string name) {
        if (name == Circle::name)
            return std::make_unique<Circle>(1, 3);
        if (name == Rectangle::name)
            return std::make_unique<Rectangle>(2, 6);

        return nullptr;
    }
};

class Color {
public:
    int red;
    int green;
    int blue;

    Color(int r, int g, int b): red(r), green(g), blue(b) {}
};

class Font {
public:
    std::string font;

    Font(std::string font): font(font) {}
};

class Composite {
public:
    Shape shape;
    Color color;
    Font font;

    Composite(Shape s, Color c, Font f): shape(s), color(c), font(f) {}
    virtual ~Composite(){}

    void show() {
        std::cout << "Drawing at (" << shape.x << ", " << shape.y << ") with color (" << color.red << ", " << color.green << ", " << color.blue << ") and font " << font.font << std::endl;

    }

};

int main(void) {
    auto circle = ShapeFactory::create("circle");
    auto rec = ShapeFactory::create("rectangle");

    circle->draw();
    rec->draw();

    auto com = Composite(Circle(12, 34), Color(124, 227, 145), Font("Arial"));
    com.show();


    return 0;
}
