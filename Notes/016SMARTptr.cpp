//
// Created by 易治行 on 2025/4/23.
//

/*
 * 智能指针分为三类：
 * - `unique_ptr`: 独占所有权，同一时刻只能有一个指针指向同一个实例，不能复制和赋值，通过 `move` 函数转移所有权，旧的指针自动销毁
 * - `shared_ptr`: 多个 `shared_ptr` 能够指向同一个实例，当所有的指针被销毁时，该实例被销毁
 * - `weak_ptr`: ...
 */

#include <memory>
#include <iostream>


int main(void) {

    std::unique_ptr<int> p1(new int(10));
    // NOTE: `p1` 变为空指针了
    std::unique_ptr<int> p2 = std::move(p1);
    std::cout << *p2 << std::endl;

    // NOTE: 可以使用 `make_unique` 函数创建一个类的 unique ptr
    auto p3 = std::make_unique<int>(10);
    std::cout << *p3 << std::endl;

    // shared_ptr:

    std::shared_ptr<int> q1(new int(10));
    std::shared_ptr<int> q2 = q1;

    std::cout << *q1 << std::endl;
    std::cout << *q2 << std::endl;

    // 通过 `reset` 方法释放 `shared_ptr`
    q1.reset();
    q2.reset();

    return 0;
}