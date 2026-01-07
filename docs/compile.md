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
  * **如果`src`的不同子目录下都有`helloworld.cpp`，可以`cmake --build build --target runoob_cpp_helloworld`作为区分，这里target 名 ≠ 输出文件名，这是刻意的工程设计，避免跨模块重名，target 名具备上下文**
* 运行：`./build/runoob_cpp/helloworld`，或`./build/runoob_cpp/runoob_cpp_helloworld`
* **清理编译的二进制文件：`rm -rf build`**
* CMake 并没有取代 make，而是生成 Makefile。

```bash
cd build
make helloworld
make
```

* 编译生成文件的含义和用途
  
```bash
~/cpp_primer_plus_6th/build/CMakeFiles/runoob_cpp_helloworld.dir$ ls
DependInfo.cmake  build.make  cmake_clean.cmake  compiler_depend.make  compiler_depend.ts  depend.make  flags.make  link.txt  progress.make  src

runoob_cpp_helloworld.dir/
├── src/                      # 源文件的“构建镜像”
├── build.make                # make 的核心构建规则
├── depend.make               # 源文件依赖关系
├── compiler_depend.make      # 编译器级依赖
├── compiler_depend.ts        # 依赖时间戳
├── DependInfo.cmake          # CMake 的依赖描述
├── flags.make                # 编译参数快照
├── link.txt                  # 链接命令
├── cmake_clean.cmake         # target 清理规则
└── progress.make             # 构建进度管理

```
