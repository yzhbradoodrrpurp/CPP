//
// Created by 易治行 on 2025/4/23.
//

/*
 * 智能指针分为三类：
 * - `unique_ptr`: 独占所有权，同一时刻只能有一个指针指向同一个对象，不能复制和赋值，通过 `move` 方法转移所有权
 * - `shared_ptr`: ...
 * - `weak_ptr`: ...
 */

#include <memory>
#include <iostream>


int main(void) {

    std::unique_ptr<int> p_1(new int(10));
    std::unique_ptr<int> p_2 = std::move(p_1);

    std::cout << *p_2 << std::endl;

    //todo: finish smart ptr... maybe next week...

    return 0;
}