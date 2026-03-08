#include "../src/SquareSumDoubleSumChecker.cpp"
#include <iostream>

int main() {
    SquareSumDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "SquareSumDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "SquareSumDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
