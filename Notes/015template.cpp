//
// Created by 易治行 on 2025/4/23.
//

// NOTE: 也可写作 `template <class type>`
template <typename type1>
template <typename type2>

// NOTE: 函数模版，作用于函数中
type1 GetSum(type1 arr[]) {
     auto sum = 0;

    for (auto i: arr) {
        sum += i;
    }

    return sum;
}

template <typename type2>
// NOTE: 类模版，做用于类中的属性
class Array{

};
