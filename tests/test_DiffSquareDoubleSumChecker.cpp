#include "../src/DiffSquareDoubleSumChecker.hpp"
#include <iostream>

int main() {
    DiffSquareDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "DiffSquareDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "DiffSquareDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
