cmake_minimum_required(VERSION 3.10)

# プロジェクト設定
project(DoubleSumChecker)

# C++の標準バージョン
set(CMAKE_CXX_STANDARD 17)

# ライブラリのビルド
add_library(DoubleSumChecker STATIC
    src/AbstractDoubleSumChecker.cpp
)

# テストケースリストファイルを読み込む
file(STRINGS "list.txt" FILES)

foreach(FILE ${TEST_FILES})
    add_library(src/${FILE}.cpp)
endforeach()

file(STRINGS "list.txt" TEST_FILES)

foreach(TEST_NAME ${TEST_FILES})
    message(STATUS "Registering test case: ${TEST_NAME}")
    add_executable(test_${TEST_NAME} tests/test_${TEST_NAME}.cpp)
    target_link_libraries(test_${TEST_NAME} DoubleSumChecker)
endforeach()