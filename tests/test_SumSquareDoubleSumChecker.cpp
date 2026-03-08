#include "../src/SumSquareDoubleSumChecker.cpp"
#include <iostream>

int main() {
    SumSquareDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "SumSquareDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "SumSquareDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
