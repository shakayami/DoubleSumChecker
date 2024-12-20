#include "../src/MultiplyDoubleSumChecker.cpp"
#include <iostream>

int main() {
    MultiplyDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "MultiplyDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "MultiplyDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
