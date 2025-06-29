#include "../src/SubDoubleSumChecker.hpp"
#include <iostream>

int main() {
    SubDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "SubDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "SubDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
