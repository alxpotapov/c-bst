cmake_minimum_required(VERSION 2.8)
project(BST)
add_subdirectory(tests)
enable_testing()

add_test(NAME TreeTest COMMAND TreeTest)
