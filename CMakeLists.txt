cmake_minimum_required(VERSION 3.28)
project(testProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(testProject main.cpp
        Student.cpp
        Student.h
        Sales_item.cpp
        Sales_item.h
)
