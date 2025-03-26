//
// Created by 易治行 on 2025/3/26.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // 定一个以 `int` 为内容类型的 vector
    vector<int> len;

    // NOTE: 使用 `push_back` 方法向末尾添加元素，类似于 `append`
    for (int i = 0; i < 10; i++)
        len.push_back(i);

    for (auto i : len)
        cout << i << " ";
    cout << endl;

    // NOTE: 使用 `pop_back` 来删除最后一个元素，相当于 默认的 `pop`
    len.pop_back();

    for (auto i : len)
        cout << i << " ";
    cout << endl;

    // NOTE: `begin` 是指向 vector 中第一个元素的迭代器
    // NOTE: `end` 是指向 vector 中最后一个元素的迭代器

    // NOTE: `insert` 接收指向某个位置的迭代器和一个元素，向那个位置插入该元素
    len.insert(len.begin() + 3, 100);

    for (auto i : len)
        cout << i << " ";
    cout << endl;

    // NOTE: erase 接收某一位置的迭代器，删除那个位置的元素
    len.erase(len.end() - 1);

    for (auto i : len)
        cout << i << " ";
    cout << endl;

    return 0;
}