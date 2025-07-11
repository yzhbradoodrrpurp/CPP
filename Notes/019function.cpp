//
// Created by 易治行 on 2025/5/14.
//

#include <algorithm> // 使用 `sort` 必须导入
#include <numeric> // 使用 `accumulate` 必须导入
#include <iostream>
#include <vector>

// NOTE: 类型必须为 `bool`，接受两个参数，分别表示容器中任意两个元素
bool compare_strategy(int a, int b) {
    return a > b; // 从大到小排序: a 应该排在 b 前面吗，如是 `true` 则应该
}

// NOTE: 自选合适的类型，接受两个参数，`a` 表示目前累计的值，`b` 表示容器中下一个值
int accumulate_strategy(int accumulated_value, int next_value) {
    return accumulated_value * next_value;
}

// NOTE: 不用返回值，一般为 `void`
void iterate_strategy(int value) {
    std::cout << value << std::endl;
}

int main() {
    std::vector<int> l = {1, 5, 2, 8, 5, 6, 9};

    // NOTE: `std::sort` 用于对一个 sequential container 进行排序
    // NOTE: 第一个第二个参数分别为被排序的 sequential container 的初始指针和结束指针
    // NOTE: 第三个参数是可选的，定义排序的规则
    std::sort(l.begin(), l.end(), compare_strategy);
    std::for_each(l.begin(), l.end(), iterate_strategy);

    // NOTE: `std::accumulate` 用于对 container 进行累计
    // NOTE: 第一个第二个参数分别为 container 的初始指针和结束指针
    // NOTE: 第三个参数是初始值
    // NOTE: 第四个参数是自定义的策略
    int accumulated_value = std::accumulate(l.begin(), l.end(), 1, accumulate_strategy);
    std::cout << accumulated_value << std::endl;

    // NOTE: `std::find` 用于在 container 中寻找某个值
    auto one = std::find(l.begin(), l.end(), 5);

    if (one == l.end())
        std::cout << "Not found" << std::endl;
    else
        std::cout << *one << std::endl;

    return 0;
}