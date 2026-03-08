#include "../src/NandDoubleSumChecker.cpp"
#include <iostream>

int main() {
    NandDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "NandDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "NandDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
