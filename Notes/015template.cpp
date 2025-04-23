//
// Created by 易治行 on 2025/4/23.
//

template <class type>

type GetSum(type arr[]) {
    type sum = 0;

    for (auto i: arr) {
        sum += i;
    }

    return sum;
}