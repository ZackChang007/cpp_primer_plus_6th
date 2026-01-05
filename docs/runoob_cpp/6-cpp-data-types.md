# C++ 数据类型

* <https://www.runoob.com/cplusplus/cpp-data-types.html>

## 基本的内置类型

* 七种基本的 C++ 数据类型：bool, char, int, float, double, void, wchar_t

* 下面实例会输出您电脑上各种数据类型的大小
  * [data_type](../../src/runoob_cpp/data_type.cpp)
  * `g++ data_type.cpp -o data_type`, `./data_type`

## 类型转换

### 静态转换（Static Cast）

* 静态转换是将一种数据类型的值强制转换为另一种数据类型的值。
* 静态转换通常用于比较类型相似的对象之间的转换，例如将 int 类型转换为 float 类型。
* 静态转换不进行任何运行时类型检查，因此可能会导致运行时错误。

```c++
int i = 10;
float f = static_cast<float>(i); // 静态将int类型转换为float类型
```

### 动态转换（Dynamic Cast）

* 动态转换（dynamic_cast）是 C++ 中用于在继承层次结构中进行向下转换（downcasting）的一种机制。
* 动态转换通常用于将一个基类指针或引用转换为派生类指针或引用。
* 动态转换在运行时进行类型检查。如果转换失败，对于指针类型会返回 `nullptr`，对于引用类型则会抛出 `std::bad_cast` 异常。
* **语法：`dynamic_cast<目标类型>(表达式)`**

* 指针类型的动态转换：
  * [ptr_dynamic_cast](../../src/runoob_cpp/ptr_dynamic_cast.cpp)
  * `g++ ./ptr_dynamic_cast.cpp -o ptr_dynamic_cast`, `./ptr_dynamic_cast`

* 引用类型的动态转换：
  * [ref_dynamic_cast](../../src/runoob_cpp/ref_dynamic_cast.cpp)
  * `g++ ./ref_dynamic_cast.cpp -o ref_dynamic_cast`, `./ref_dynamic_cast`

### 常量转换（Const Cast）

* 常量转换用于将 const 类型的对象转换为非 const 类型的对象。
* 常量转换只能用于转换掉 const 属性，不能改变对象的类型。

```c++
const int i = 10;
int& r = const_cast<int&>(i); // 常量转换，将const int转换为int
```

### 重新解释转换（Reinterpret Cast）

* 重新解释转换将一个数据类型的值重新解释为另一个数据类型的值，通常用于在不同的数据类型之间进行转换。
* 重新解释转换不进行任何类型检查，因此可能会导致未定义的行为。

```c++
int i = 10;
float f = reinterpret_cast<float&>(i); // 重新解释将int类型转换为float类型
```
