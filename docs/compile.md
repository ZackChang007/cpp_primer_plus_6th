# 编译

## Makefile

* 项目根目录放置Makefile
  * 编译所有示例：`make`
  * 编译单个示例：`make helloworld`

* 运行编译好的程序

```bash
# 显式运行
./build/runoob_cpp/helloworld

# 临时加 PATH
export PATH=$PWD/build/runoob_cpp:$PATH
helloworld

# 先编译，再运行
make helloworld && ./build/runoob_cpp/helloworld
```

## CMake

* 根目录生成CMakeLists.txt
* 一次性初始化：`cmake -S . -B build`
* 编译所有：`cmake --build build`
* 编译单个：`cmake --build build --target helloworld`
* 运行：`./build/runoob_cpp/helloworld`
* CMake 并没有取代 make，而是生成 Makefile。

```bash
cd build
make helloworld
make
```
