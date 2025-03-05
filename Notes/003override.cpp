//
// Created by 易治行 on 2025/3/5.
//

/*
在C++中可以使用相同的函数名来定义不同的函数，
区别在于函数的签名必须不同，也就是说，
传入的参数个数、类型和函数的类型等必须不同
 */

int max(int, int);
float max(float, float);
double max(double, double);


int main(void) {

    // ...

    return 0;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

float max(float a, float b) {
    if (a > b)
        return a;
    else
        return b;
}

double max(double a, double b) {
    if (a > b)
        return a;
    else
        return b;
}