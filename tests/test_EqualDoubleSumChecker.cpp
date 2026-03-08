#include "../src/EqualDoubleSumChecker.cpp"
#include <iostream>

int main() {
    EqualDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "EqualDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "EqualDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
