#include "../src/MinDoubleSumChecker.cpp"
#include <iostream>

int main() {
    MinDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "MinDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "MinDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
