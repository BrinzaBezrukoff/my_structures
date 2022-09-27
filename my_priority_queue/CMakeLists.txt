cmake_minimum_required(VERSION 3.23)
project(priority_queue)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(priority_queue
        main.cpp
        prioirty_queue.h)
