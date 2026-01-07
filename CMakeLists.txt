cmake_minimum_required(VERSION 3.16)

# 1️⃣ 定义整个项目
project(cpp_primer_plus LANGUAGES CXX)

# 2️⃣ 统一 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3️⃣ 找到 src 下所有一级子目录（模块）
file(GLOB SUBDIRS RELATIVE
     ${CMAKE_SOURCE_DIR}/src
     ${CMAKE_SOURCE_DIR}/src/*)

# 4️⃣ 遍历每个模块
foreach(subdir ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/src/${subdir})

        # 5️⃣ 找到模块内所有 cpp
        file(GLOB SRC_FILES
             ${CMAKE_SOURCE_DIR}/src/${subdir}/*.cpp)

        foreach(src ${SRC_FILES})

            # 6️⃣ 提取文件名（不含后缀）
            get_filename_component(name ${src} NAME_WE)

            # 7️⃣ 构造工程级 target 名
            set(target ${subdir}_${name})

            # 8️⃣ 定义可执行目标
            add_executable(${target} ${src})

            # 9️⃣ 控制可执行文件输出路径
            set_target_properties(${target} PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY
                ${CMAKE_BINARY_DIR}/${subdir}
            )

        endforeach()
    endif()
endforeach()
