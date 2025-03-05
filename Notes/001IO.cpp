// 包含标准输入输出库的头文件
#include <iostream>

int main(void) {
    // `std` 是C++中标准库的命名空间 (namespace) ，命名空间用于组织代码，避免命名冲突
    // `cout` 将数据输出到标准输出 (通常是显示器)
    // `<<` 是插入运算符，用于将右侧插入到左侧的流中，可以使用多个 `<<` 将多个数据插入到同一流中
    // `endl` 是一个操纵符，用于换行并且刷新输出缓冲区，和 `\n` 有细微的区别
    std::cout << "Hello world!" << std::endl;

    const char *name = "Zhihang Yi";
    std::cout << "Good morning, " << name << ". Have a good day!" << std::endl;

    // `cin` 是从标准输入中读取数据的函数
    // `>>` 是提取运算符，将左侧提取到的数据存储在右侧的变量中
    int age;
    std::cin >> age; // 遇到换行符或者空格会停止输入

    // 可以连续读取多个值，同样遇到换行符和空格会停止输入
    double height, weight;
    std::cin >> height >> weight;

    std::cout << "Hello " << name << ", you are " << age << " years old." << std::endl;
    std::cout << "height: " << height << " " << "weight: " << weight << std::endl;

    // C++中的强制类型转换可以使用 `type()` 的形式，和Python中的相似
    std::cout << "Hello " << name << ", you are " << double(age) << " years old." << std::endl;

    return 0;
}