cmake_minimum_required(VERSION 3.28.0)
project(c105-book-sample VERSION 1.0.0 LANGUAGES CXX)

find_package(Threads REQUIRED)

add_subdirectory(lib)
add_subdirectory(src)
