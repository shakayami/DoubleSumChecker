#include "../src/GcdDoubleSumChecker.cpp"
#include <iostream>

int main() {
    GcdDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "GcdDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "GcdDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
