cmake_minimum_required(VERSION 3.10)

# プロジェクト設定
project(DoubleSumChecker)

# C++の標準バージョン
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# テストを有効化
enable_testing()

# ライブラリのビルド
add_library(DoubleSumChecker STATIC
    src/AbstractDoubleSumChecker.cpp
)

# テストケースリストファイルを読み込む
file(STRINGS "list.txt" TEST_FILES)

foreach(TEST_NAME ${TEST_FILES})
    message(STATUS "Registering test case: ${TEST_NAME}")
    add_executable(test_${TEST_NAME} tests/test_${TEST_NAME}.cpp)
    target_link_libraries(test_${TEST_NAME} PRIVATE DoubleSumChecker)
    add_test(NAME test_${TEST_NAME} COMMAND test_${TEST_NAME})
endforeach()
