#include "../src/MaxDoubleSumChecker.cpp"
#include <iostream>

int main() {
    MaxDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "MaxDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "MaxDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
