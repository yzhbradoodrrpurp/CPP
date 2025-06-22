//
// Created by 易治行 on 2025/5/14.
//

#include <iostream>
#include <list>
#include <cassert>

using namespace std;

int main(void) {
    list<int> l;
    int len;
    cout << "Enter the length of the list: ";
    cin >> len;

    cout << "Enter the elements of the list: ";
    for (int i = 0; i < len; i++) {
        int element;
        cin >> element;
        l.push_back(element);
    }

    cout << "Enter the index you want to delete: ";
    int deleted_idx;
    cin >> deleted_idx;

    assert(deleted_idx < len and deleted_idx >= 0);

    // NOTE: `list` 不能像 `vector` 那样可以直接 `l.erase(l.begin() + idx)` 来删除第 `idx` 的元素
    auto it = l.begin();
    std::advance(it, deleted_idx);
    l.erase(it);

    return 0;
}