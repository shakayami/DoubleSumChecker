#include "../src/OrDoubleSumChecker.cpp"
#include <iostream>

int main() {
    OrDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "OrDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "OrDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
