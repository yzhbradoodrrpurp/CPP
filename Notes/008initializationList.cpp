//
// Created by 易治行 on 2025/3/19.
//

#include <iostream>

using namespace std;

class CPU {

public:
    // 使用 `enum` 定义 CPU 的架构
    enum Architecture {x86, ARM64, MIPS, RISC_V};

private:
    int frequency; // GHz
    int capacity; // MB
    Architecture architecture;

public:
    /*
     * // NOTE: 初始化列表是在构造函数后面通过冒号直接进行赋值
     * 使用这种方式能够避免成员变量先被初始化为默认值，然后再赋为特定值的现象
     * 在有些情况中，只有这样赋值才行得通
     */
    CPU(int frequency, int capacity, Architecture architecture) : frequency(frequency), capacity(capacity), architecture(architecture) {}

    // other methods...
};

class RAM {

public:
    enum Type {DDR1, DDR2, DDR3, DDR4};

private:
    int capacity;
    int frequency;
    Type type;

public:
    RAM(int capacity, int frequency, Type type) : capacity(capacity), frequency(frequency), type(type) {}

    // other methods...
};

class Computer {

private:
    CPU cpu;
    RAM ram;

public:
    Computer(CPU cpu, RAM ram) : cpu(cpu), ram(ram) {}

    // other methods...
};

int main() {
    // 标明类名
    CPU cpu = CPU(1000, 30, CPU::ARM64);
    RAM ram = RAM(10000, 1000, RAM::DDR4);

    Computer myComputer = Computer(cpu, ram);

    return 0;
}