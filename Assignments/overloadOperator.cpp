#include <iostream>


class Complex {

private:
    double real;
    double imag;

public:
    Complex(double real, double imag): real(real), imag(imag) {}
    Complex(): real(0), imag(0) {}

    virtual ~Complex() {}

    friend Complex operator+(const Complex &self, const Complex &other);

    // 前缀
    void operator++() {
        real += 1;
        imag += 1;
    }

    // 前缀
    void operator--() {
        real -= 1;
        imag -= 1;
    }

    // 后缀
    void operator++(int) {
        real += 1;
        imag += 1;
    }

    // 后缀
    void operator--(int) {
        real -= 1;
        imag -= 1;
    }

    void print() {
        std::cout << "real: " << this->real << std::endl;
        std::cout << "imag: " << this->imag << std::endl;
    }
};

// NOTE: 使用友元函数的方式重载运算符函数
Complex operator+(const Complex &self, const Complex &other) {
    double real = self.real + other.real;
    double imag = self.imag + other.imag;

    return Complex(real, imag);
}


int main() {

    Complex a = Complex(10, 5);
    Complex b = Complex(7, 8);

    Complex c = a + b;
    c.print();

    ++a;
    a.print();

    a++;
    a.print();

    --b;
    b.print();
    b--;
    b.print();

    return 0;
}