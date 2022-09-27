cmake_minimum_required(VERSION 3.22)
project(my_queue)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        my_queue
        main.cpp
        queue/Queue.cpp
        queue/VectorQueue.cpp
        queue/ListQueue.cpp
        list/List.cpp
)
