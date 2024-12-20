#include "../src/AndDoubleSumChecker.cpp"
#include <iostream>

int main() {
    AndDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "AndDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "AndDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
