#include "../src/XorDoubleSumChecker.cpp"
#include <iostream>

int main() {
    XorDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "XorDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "XorDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
