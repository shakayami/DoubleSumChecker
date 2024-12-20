import os
import sys
import yaml

# テンプレートコード
class_template = """#ifndef {CLASS_NAME_UPPER}_HPP
#define {CLASS_NAME_UPPER}_HPP

#include "AbstractDoubleSumChecker.hpp"
#include <random>

class {CLASS_NAME} : public AbstractDoubleSumChecker<long long> {{
    using T = long long;

    T func(T x, T y) override {{
        // 関数をここに実装
    }}

    T SolveFasterAlgorithm(const std::vector<T>& A) override {{
        int N=A.size();
        T result = 0;
        // 高速アルゴリズムをここに実装
        return result;
    }}

    T RandomElementGenerator() override {{
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(1, 100);
        return dist(engine);
    }}
}};

#endif // {CLASS_NAME_UPPER}_HPP
"""

test_template = """#include "../src/{CLASS_NAME}.cpp"
#include <iostream>

int main() {{
    {CLASS_NAME} checker;

    if (checker.Verification()) {{
        std::cout << "{CLASS_NAME} Test Passed" << std::endl;
        return 0;
    }} else {{
        std::cerr << "{CLASS_NAME} Test Failed" << std::endl;
        return 1;
    }}
}}
"""

# ファイルを生成
def generate_class_and_test(class_name):
    class_name_upper = class_name.upper()
    class_content = class_template.format(
        CLASS_NAME=class_name,
        CLASS_NAME_UPPER=class_name_upper,
    )
    test_content = test_template.format(CLASS_NAME=class_name)

    # src フォルダにヘッダーファイルを作成
    with open(f"src/{class_name}.cpp", "w") as class_file:
        class_file.write(class_content)

    # tests フォルダにテストファイルを作成
    with open(f"tests/test_{class_name}.cpp", "w") as test_file:
        test_file.write(test_content)

    print(f"Generated {class_name}.cpp and test_{class_name}.cpp")

def update_cmake(class_name):
    cmake_file = "CMakeLists.txt"

    # 既存のCMakeLists.txtを読み込み
    with open(cmake_file, "r") as f:
        lines = f.readlines()

    # 新しいエントリを追加
    library_entry = f"    src/{class_name}.cpp\n"
    test_entry = f"add_executable(test_{class_name} tests/test_{class_name}.cpp)\n"
    target_entry = f"target_link_libraries(test_{class_name} DoubleSumChecker)\n"

    if library_entry not in lines:
        idx = lines.index("    src/AbstractDoubleSumChecker.hpp\n")
        lines.insert(idx + 1, library_entry)

    if test_entry not in lines:
        lines.append(test_entry)

    if target_entry not in lines:
        lines.append(target_entry)
    
    lines.append("\n")

    # ファイルを上書き
    with open(cmake_file, "w") as f:
        f.writelines(lines)

    print(f"CMakeLists.txt updated with {class_name}")


def add_test_to_ci(class_name):
    CI_YML_PATH = ".github/workflows/ci.yml"
    with open(CI_YML_PATH, "r") as f:
        lines = f.readlines()
    lines.append(f"          ./test_{class_name}\n")
    with open(CI_YML_PATH, "w") as f:
        f.writelines(lines)

    print(f"{CI_YML_PATH} updated with {class_name}")


if __name__=="__main__":
    class_name=sys.argv[1]+"DoubleSumChecker"
    update_cmake(class_name)
    generate_class_and_test(class_name)
    add_test_to_ci(class_name)

