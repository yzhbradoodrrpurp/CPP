//
// Created by 易治行 on 2025/3/9.
//

#include <iostream>
#include <string>

using namespace std;

class Car {

/* C++ 提供三种用于控制访问的修饰符: `private`, `public`, `protected`
 * `private` 只允许在类内部访问该成员
 * `public` 允许在类外部访问该成员
 * `protected` 允许在类内部和子类中访问该成员
 * NOTE: 控制访问修饰符的作用域为从该行一直到下一个控制访问修饰符之前
 */

protected:
    string owner;
    string brand;
    int price;
    int maxSpeed;

public:
    // NOTE: C++ 使用和类名同名的构造体来进行初始化，类似于 Python 中的 `__init__`
    // 函数中传入参数时可以像 Python 一样设置默认参数
    // 构造函数也可以重载
    Car(string owner="Zhihang Yi", string brand="Ferrari", int price=1000000, int maxSpeed=460) {
        // NOTE: C++ 中用 `this` 来指代该实例的指针
        this->owner = owner;
        this->brand = brand;
        this->price = price;
        this->maxSpeed = maxSpeed;
    }

    // NOTE: `static` 表明该方法属于类，而不是单个实例对象
    static void startEngine() {
        cout << "Vroooom" << endl;
    }

    // NOTE: 常函数的写法，区别于 `const void getInfo();`
    void getInfo() const {
        cout << "Owner: " << this->owner << endl;
        cout << "Brand: " << this->brand << endl;
        cout << "Price: " << this->price << endl;
        cout << "Max Speed: " << this->maxSpeed << endl;
    }

};

int main(void) {
    Car myCar = Car("Yzhbradoodrrpurp", "Porsche", 2000000, 370);

    myCar.getInfo();
    myCar.startEngine();

    return 0;
}
