cmake_minimum_required(VERSION 3.10)
project (lqengine_client)
project (lqengine)

set(CMAKE_CXX_STANDARD 17)

add_library(lqengine
    LQEngine.cpp
    LQEngine.h
    LQDatabase.cpp
    LQDatabase.h
    LQQuestion.cpp
    LQQuestion.h)


add_executable(lqengine_client main.cpp)
target_link_libraries(lqengine_client lqengine)
