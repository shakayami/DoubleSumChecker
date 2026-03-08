#include "../src/CubeSumDoubleSumChecker.cpp"
#include <iostream>

int main() {
    CubeSumDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "CubeSumDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "CubeSumDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
