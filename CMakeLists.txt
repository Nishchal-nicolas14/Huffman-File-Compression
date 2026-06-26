cmake_minimum_required(VERSION 3.15)
project(nca VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(nca
    main.cpp
    FileManager.cpp
    HuffmanTree.cpp
)

target_include_directories(nca PRIVATE ${CMAKE_SOURCE_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(nca PRIVATE -O2)
endif()

install(TARGETS nca DESTINATION bin)