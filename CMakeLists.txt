cmake_minimum_required(VERSION 3.10)

project(DoubleSumChecker)

set(CMAKE_CXX_STANDARD 17)

add_library(DoubleSumChecker STATIC
    src/AbstractDoubleSumChecker.hpp
    src/AddDoubleSumChecker.cpp
    src/MultiplyDoubleSumChecker.cpp
)

add_executable(test_AddDoubleSumChecker tests/test_AddDoubleSumChecker.cpp)
target_link_libraries(test_AddDoubleSumChecker DoubleSumChecker)

add_executable(test_MultiplyDoubleSumChecker tests/test_MultiplyDoubleSumChecker.cpp)
target_link_libraries(test_MultiplyDoubleSumChecker DoubleSumChecker)
