//
// Created by 易治行 on 2025/3/19.
//

#include <iostream>
#include <string>

using namespace std;

class RAM {

public:
    enum RAMType {DDR4, DDR3, DDR2, DDR1};

private:
    int capacity;
    RAMType type;
    int frequency;

public:
    RAM(int capacity, RAMType type, int frequency) {
        this->capacity = capacity;
        this->type = type;
        this->frequency = frequency;
    }

    ~RAM() {
        // ...
    }

    // methods...
};


class CD_ROM {

public:
    enum InterfaceType {SATA, USB};
    enum InstallationType {external, built_in};

private:
    InterfaceType interface;
    int capacity;
    InstallationType installation;

public:
    CD_ROM(InterfaceType interface, int capacity, InstallationType installation) {
        this->interface = interface;
        this->capacity = capacity;
        this->installation = installation;
    }

    ~CD_ROM() {
        // ...
    }

    // methods...
};

class CPU {

private:
    int frequency;

public:
    CPU(int frequency) {
        this->frequency = frequency;
    }

    ~CPU() {
        // ...
    }

    // methods...

};

class Computer {

private:
    CPU cpu;
    RAM ram;
    CD_ROM cd_rom;

public:
    Computer(const CPU& cpu, const RAM& ram, const CD_ROM& cd_rom):cpu(cpu), ram(ram), cd_rom(cd_rom) {
        this->cpu = cpu;
        this->ram = ram;
        this->cd_rom = cd_rom;
    }

    ~Computer() {
        // ...
    }

};


int main() {
    CPU cpu = CPU(100);
    CD_ROM cd_rom = CD_ROM(CD_ROM::SATA, 100, CD_ROM::built_in);
    RAM ram = RAM(100, RAM::DDR4, 100);

    Computer computer = Computer(cpu, ram, cd_rom);

    return 0;
}