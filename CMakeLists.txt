cmake_minimum_required(VERSION 3.10)

project(WinVM
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WinVM
    src/main.cpp

    src/core/VM.cpp
    src/core/VM.h

    src/core/Memory.cpp
    src/core/Memory.h
)
