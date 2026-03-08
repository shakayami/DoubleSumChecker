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

# list.txt と tests/ の整合性チェック（欠落テスト検出）
file(GLOB TEST_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "tests/test_*.cpp")
set(DISCOVERED_TEST_NAMES "")
foreach(TEST_SOURCE ${TEST_SOURCES})
    string(REGEX REPLACE "^tests/test_(.+)\\.cpp$" "\\1" DISCOVERED_TEST_NAME "${TEST_SOURCE}")
    list(APPEND DISCOVERED_TEST_NAMES "${DISCOVERED_TEST_NAME}")
endforeach()

set(MISSING_TESTS "")
foreach(TEST_NAME ${TEST_FILES})
    set(TEST_SOURCE "tests/test_${TEST_NAME}.cpp")
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${TEST_SOURCE}")
        list(APPEND MISSING_TESTS "${TEST_SOURCE}")
    endif()
endforeach()

if(MISSING_TESTS)
    list(JOIN MISSING_TESTS "\n  - " MISSING_TESTS_JOINED)
    message(FATAL_ERROR "list.txt に対応するテストファイルが不足しています:\n  - ${MISSING_TESTS_JOINED}")
endif()

set(UNLISTED_TESTS "")
foreach(DISCOVERED_TEST_NAME ${DISCOVERED_TEST_NAMES})
    list(FIND TEST_FILES "${DISCOVERED_TEST_NAME}" TEST_INDEX)
    if(TEST_INDEX EQUAL -1)
        list(APPEND UNLISTED_TESTS "tests/test_${DISCOVERED_TEST_NAME}.cpp")
    endif()
endforeach()

if(UNLISTED_TESTS)
    list(JOIN UNLISTED_TESTS "\n  - " UNLISTED_TESTS_JOINED)
    message(FATAL_ERROR "tests/ にあるが list.txt に未登録のテストファイルがあります:\n  - ${UNLISTED_TESTS_JOINED}")
endif()

foreach(TEST_NAME ${TEST_FILES})
    message(STATUS "Registering test case: ${TEST_NAME}")
    add_executable(test_${TEST_NAME} tests/test_${TEST_NAME}.cpp)
    target_link_libraries(test_${TEST_NAME} PRIVATE DoubleSumChecker)
    add_test(NAME test_${TEST_NAME} COMMAND test_${TEST_NAME})
endforeach()
