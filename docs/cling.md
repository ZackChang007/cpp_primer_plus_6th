# cling

* <https://github.com/root-project/cling>

## 安装

* Cling 依赖 LLVM 和 Clang，因此推荐联建 LLVM + Cling，避免手动先编译再构建。

* 步骤 1. 克隆 LLVM 和 Cling 源码

```bash
# 克隆 LLVM 主 repo（包含 Clang 等）
git clone git@github.com:root-project/llvm-project.git
cd llvm-project
# 这里 cling-latest 分支包含 Cling 适配的 LLVM/Clang 最新开发分支。
git checkout cling-latest
cd ..

# 克隆 Cling
git clone git@github.com:root-project/cling.git
```

* 步骤 2. 创建构建目录并执行 CMake

```bash
mkdir cling-build && cd cling-build
cmake -DLLVM_EXTERNAL_PROJECTS=cling -DLLVM_EXTERNAL_CLING_SOURCE_DIR=../cling/ -DLLVM_ENABLE_PROJECTS="clang" -DLLVM_TARGETS_TO_BUILD="host;NVPTX" -DCMAKE_BUILD_TYPE=Release ../llvm-project/llvm
cmake --build . --target clang cling
```

* 检查安装成功：

```bash
cd ./cling-build/bin
./cling --version
./cling --help
```

## 运行

### cling中交互式运行

```bash
cd ./cling-build/bin

# 进入交互模式
./cling

#include <iostream>
using namespace std;
int x = 42;
cout << x << endl;

# 或者不进入交互模式，直接在命令行：
./cling '#include <iostream>' 'std::cout << "Hello from Cling" << std::endl;'
./cling '#include <stdio.h>' 'printf("Hello World!\n");'
```

* cling基本命令

```bash
.help：显示帮助菜单。
.L <文件名>：加载并包含一个 C++ 源文件或库。
.I <目录>：添加头文件搜索路径。
.q：退出解释器。
```

### jupyter

* 安装xeus-cling = Cling + Jupyter 内核协议（ZeroMQ）

```mathematica
conda env
├── jupyterlab / notebook
├── xeus
├── xeus-cling
│   └── 内嵌 cling + clang + llvm
└── kernelspec (C++17 / C++20 / CUDA)
```

```bash
# 查看cpp版本
echo 'int main(){}' | g++ -dM -E -x c++ - | grep __cplusplus
# 返回#define __cplusplus 201703L，对应C++17

# 创建并激活conda env
conda create -n cling-jupyter python=3.11 -y
# 如果遇到wsl2网络问题尝试：
unset all_proxy ALL_PROXY GIT_PROXY_COMMAND http_proxy https_proxy; env | grep -i proxy || echo 'No proxy env'; conda create -n cling-jupyter python=3.11 -y

conda activate cling-jupyter


# 安装 Jupyter
unset all_proxy ALL_PROXY GIT_PROXY_COMMAND http_proxy https_proxy; env | grep -i proxy || echo 'No proxy env'; conda install -c conda-forge jupyterlab -y


# 安装 xeus-cling
conda install -c conda-forge xeus-cling -y
```

* 启动jupyter lab: `jupyter lab`，选择kernel`C++17`

```c++
// cell 1
#include <iostream>
std::cout << "Hello Cling in Jupyter" << std::endl;

// cell 2
int x = 10;
x += 5;
x

// cell 3
x * 2
```
