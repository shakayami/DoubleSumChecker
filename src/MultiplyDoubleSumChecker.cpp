#ifndef MULTIPLY_DOUBLE_SUM_CHECKER_CPP
#define MULTIPLY_DOUBLE_SUM_CHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class MultiplyDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return x * y;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        T sum = 0;
        T total = 0;
        for (const auto& val : A) {
            total += val;
        }
        for (const auto& val : A) {
            sum += val * (total - val);
        }
        return sum / 2;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(1, 1000000);
        return dist(engine);
    }
};

#endif // MULTIPLY_DOUBLE_SUM_CHECKER_CPP
