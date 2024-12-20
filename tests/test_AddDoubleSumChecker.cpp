#include "../src/AddDoubleSumChecker.cpp"
#include <iostream>

int main() {
    AddDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "AddDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "AddDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
