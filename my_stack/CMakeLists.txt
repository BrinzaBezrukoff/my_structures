cmake_minimum_required(VERSION 3.22)
project(my_stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_stack main.cpp stack/Stack.cpp stack/ListStack.cpp stack/VectorStack.cpp)
