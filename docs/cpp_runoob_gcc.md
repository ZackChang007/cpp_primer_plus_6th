# gcc编译器

* 程序 g++ 是将 gcc 默认语言设为 C++ 的一个特殊的版本，链接时它自动使用 C++ 标准库而不用 C 标准库。通过遵循源码的命名规范并指定对应库的名字，用 gcc 来编译链接 C++ 程序是可行的，如下例所示：`gcc main.cpp -lstdc++ -o main`
* 编译[helloworld](../src/helloworld.cpp)
  * `g++ helloworld.cpp`, `./a.out`
  * 指定生成文件名：`g++ helloworld.cpp -o helloworld`, `./helloworld`
* 如果是多个 C++ 代码文件，如 runoob1.cpp、runoob2.cpp，编译命令如下：`g++ runoob1.cpp runoob2.cpp -o runoob`
* g++ 有些系统默认是使用 C++98，我们可以指定使用 C++11 来编译 main.cpp 文件：`g++ -g -Wall -std=c++11 main.cpp`
  * `-g`：生成调试信息，这对于调试程序非常有用。
  * `-Wall`：告诉编译器显示所有警告信息。
* [g++ 常用命令选项](https://www.runoob.com/cplusplus/cpp-environment-setup.html)
