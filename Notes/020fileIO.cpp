//
// Created by 易治行 on 2025/5/21.
//

#include <iostream>
#include <fstream>
#include <string>

int main() {
    // NOTE: 使用 `std::ifstream` 打开一个文件 (必须存在)
    std::ifstream ifile("itext.txt");

    if (ifile.is_open()) {
        std::string line;
        while (std::getline(ifile, line)) {
            std::cout << line << std::endl;
        }
        // NOTE: 关闭文件
        ifile.close();
    }
    else
        std::cout << "Error opening file" << std::endl;


    // NOTE: 使用 `std::ofstream` 创建一个文件
    std::ofstream ofile("otext.txt");

    if (ofile.is_open()) {
        // NOTE: 向文件中写入内容
        ofile << "Hello, world!" << std::endl;
        ofile << "I am a human being!" << std::endl;
        // NOTE: 关闭文件
        ofile.close();
    }
    else
        std::cout << "Error opening file" << std::endl;

    return 0;
}