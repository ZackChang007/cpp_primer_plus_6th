#include <iostream>
 
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
    Base* ptr_base = new Derived; // 基类指针指向派生类对象
 
    // 将基类指针转换为派生类指针
    Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base);
 
    if (ptr_derived) {
        ptr_derived->show(); // 成功转换，调用派生类方法
    } else {
        std::cout << "Dynamic cast failed!" << std::endl;
    }
 
    delete ptr_base;
    return 0;
}