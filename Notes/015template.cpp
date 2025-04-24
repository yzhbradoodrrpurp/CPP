//
// Created by 易治行 on 2025/4/23.
//

// NOTE: 也可写作 `template <class type>`
// NOTE: 不能连续写两个 `template`
template <typename function_type>

// NOTE: 函数模版，作用于函数中
function_type GetSum(function_type arr[]) {
     function_type sum = 0;

    for (function_type i: arr) {
        sum += i;
    }

    return sum;
}


template <typename class_type>

// NOTE: 类模版，做用于类中的属性
class Pair{

private:
    class_type x;
    class_type y;

public:
    // NOTE:  调用的时候: `Pair<int> p = Pair(10, 5)`
    Pair(class_type x, class_type y): x(x), y(y) {}

    ~Pair(){}

};
