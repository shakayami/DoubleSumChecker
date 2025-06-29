#include "../src/ConstDoubleSumChecker.hpp"
#include <iostream>

int main() {
    ConstDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "ConstDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "ConstDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
