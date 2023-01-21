cmake_minimum_required(VERSION 3.0)

project(wise_pointers)

add_executable(wise_pointers main.cpp)

install(TARGETS wise_pointers RUNTIME DESTINATION bin)
