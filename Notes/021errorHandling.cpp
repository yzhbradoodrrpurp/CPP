//
// Created by 易治行 on 2025/5/28.
//

#include <iostream>


int main(void) {

    std::cout << "Enter two numbers:" << std::endl;
    int a, b;
    std::cin >> a >> b;

    try {
        if (b == 0)
            throw b;
    }
    catch (int) { // NOTE: 处理所有 `throw` 为 `int` 类型的异常
        std::cout << "The divisor is 0." << std::endl;
    }
    catch (...) { // NOTE: `...` 表示所有的异常
        std::cout << "Unknown error." << std::endl;
    }

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}