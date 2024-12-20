#ifndef CONST_DOUBLE_SUM_CHECKER_HPP
#define CONST_DOUBLE_SUM_CHECKER_HPP

#include "AbstractDoubleSumChecker.hpp"
#include <random>

class ConstDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return 1;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        int N = A.size();
        return N * (N - 1) / 2;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(0, 1e9);
        return dist(engine);
    }
};

#endif // CONST_DOUBLE_SUM_CHECKER_HPP
