#include <iostream>

int x = 100;

int main(void) {
    int x = 10;

    /*
    在C++中，`::` 叫做作用域解析运算符，用于指定某个变量、函数、类的作用域。
    当局部变量和全局变量同名时，可以用 `::` 访问全局变量。
     */

    std::cout << "local x: " << x << std::endl;
    std::cout << "global x: " << ::x << std::endl;

    return 0;
}