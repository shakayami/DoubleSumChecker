#include "../src/NorDoubleSumChecker.cpp"
#include <iostream>

int main() {
    NorDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "NorDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "NorDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
