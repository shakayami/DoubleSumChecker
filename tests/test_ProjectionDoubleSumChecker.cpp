#include "../src/ProjectionDoubleSumChecker.cpp"
#include <iostream>

int main() {
    ProjectionDoubleSumChecker checker;

    if (checker.Verification()) {
        std::cout << "ProjectionDoubleSumChecker Test Passed" << std::endl;
        return 0;
    } else {
        std::cerr << "ProjectionDoubleSumChecker Test Failed" << std::endl;
        return 1;
    }
}
