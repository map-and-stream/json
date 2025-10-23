cmake_minimum_required(VERSION 3.10)
project(json_example)

add_executable(example main.cpp)
target_link_libraries(example PRIVATE ${LIB_ALIAS})
