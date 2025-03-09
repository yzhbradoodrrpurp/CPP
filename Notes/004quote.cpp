//
// Created by 易治行 on 2025/3/9.
//

#include <iostream>

/*
 * `&` 在 C++ 中也有引用的作用
 * NOTE: 例如在函数传参时，使用 `&` 表明传递的不是一个参数的副本，而是参数本身
 */

void swap(int&, int&);

int main(void) {
    int a = 10;
    int b = 20;

    std::cout << "Before swapping: " << "a=" << a << " " << "b=" << b << std::endl;

    swap(a, b);

    std::cout << "After swapping: " << "a=" << a << " " << "b=" << b << std::endl;

    return 0;
}

void swap(int& a, int& b) {
    int c = b;
    b = a;
    a = c;
}