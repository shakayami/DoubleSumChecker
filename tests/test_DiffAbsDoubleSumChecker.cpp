#include "../src/DiffAbsDoubleSumChecker.cpp"
#include <iostream>

int main() {
    DiffAbsDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "DiffAbsDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "DiffAbsDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
