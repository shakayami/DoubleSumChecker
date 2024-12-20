cmake_minimum_required(VERSION 3.10)

project(DoubleSumChecker)

set(CMAKE_CXX_STANDARD 17)

add_library(DoubleSumChecker STATIC
    src/AbstractDoubleSumChecker.hpp
    src/OrDoubleSumChecker.cpp
    src/AndDoubleSumChecker.cpp
    src/XorDoubleSumChecker.cpp
    src/DiffAbsDoubleSumChecker.cpp
    src/MinDoubleSumChecker.cpp
    src/MaxDoubleSumChecker.cpp
    src/DiffSquareDoubleSumChecker.cpp
    src/SubDoubleSumChecker.cpp
    src/AddDoubleSumChecker.cpp
    src/MultiplyDoubleSumChecker.cpp
    src/ConstDoubleSumChecker.cpp
    src/ProjectionDoubleSumChecker.cpp
)

add_executable(test_AddDoubleSumChecker tests/test_AddDoubleSumChecker.cpp)
target_link_libraries(test_AddDoubleSumChecker DoubleSumChecker)

add_executable(test_MultiplyDoubleSumChecker tests/test_MultiplyDoubleSumChecker.cpp)
target_link_libraries(test_MultiplyDoubleSumChecker DoubleSumChecker)

add_executable(test_ConstDoubleSumChecker tests/test_ConstDoubleSumChecker.cpp)
target_link_libraries(test_ConstDoubleSumChecker DoubleSumChecker)

add_executable(test_ProjectionDoubleSumChecker tests/test_ProjectionDoubleSumChecker.cpp)
target_link_libraries(test_ProjectionDoubleSumChecker DoubleSumChecker)

add_executable(test_SubDoubleSumChecker tests/test_SubDoubleSumChecker.cpp)
target_link_libraries(test_SubDoubleSumChecker DoubleSumChecker)

add_executable(test_MaxDoubleSumChecker tests/test_MaxDoubleSumChecker.cpp)
target_link_libraries(test_MaxDoubleSumChecker DoubleSumChecker)

add_executable(test_DiffSquareDoubleSumChecker tests/test_DiffSquareDoubleSumChecker.cpp)
target_link_libraries(test_DiffSquareDoubleSumChecker DoubleSumChecker)

add_executable(test_MinDoubleSumChecker tests/test_MinDoubleSumChecker.cpp)
target_link_libraries(test_MinDoubleSumChecker DoubleSumChecker)

add_executable(test_DiffAbsDoubleSumChecker tests/test_DiffAbsDoubleSumChecker.cpp)
target_link_libraries(test_DiffAbsDoubleSumChecker DoubleSumChecker)

add_executable(test_XorDoubleSumChecker tests/test_XorDoubleSumChecker.cpp)
target_link_libraries(test_XorDoubleSumChecker DoubleSumChecker)

add_executable(test_AndDoubleSumChecker tests/test_AndDoubleSumChecker.cpp)
target_link_libraries(test_AndDoubleSumChecker DoubleSumChecker)

add_executable(test_OrDoubleSumChecker tests/test_OrDoubleSumChecker.cpp)
target_link_libraries(test_OrDoubleSumChecker DoubleSumChecker)

