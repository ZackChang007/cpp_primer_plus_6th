#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() = default; // 基类必须具有虚函数
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Derived class method" << std::endl;
    }
};

int main() {
    Derived derived_obj;
    Base& ref_base = derived_obj; // 基类引用绑定到派生类对象

    try {
        // 将基类引用转换为派生类引用
        Derived& ref_derived = dynamic_cast<Derived&>(ref_base);
        ref_derived.show(); // 成功转换，调用派生类方法
    } catch (const std::bad_cast& e) {
        std::cout << "Dynamic cast failed: " << e.what() << std::endl;
    }

    return 0;
}