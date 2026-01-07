cmake_minimum_required(VERSION 3.16)
project(cpp_primer_plus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 所有 src 下的一级子目录
file(GLOB SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/*)

foreach(subdir ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/src/${subdir})
        file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/${subdir}/*.cpp)

        foreach(src ${SRC_FILES})
            get_filename_component(target ${src} NAME_WE)
            add_executable(${target} ${src})
            set_target_properties(${target} PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${subdir}
            )
        endforeach()
    endif()
endforeach()
