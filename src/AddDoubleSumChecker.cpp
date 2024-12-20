#ifndef ADD_DOUBLE_SUM_CHECKER_HPP
#define ADD_DOUBLE_SUM_CHECKER_HPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class AddDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return x + y;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        T sum = 0;
        int N = A.size();
        for (const auto& val : A) {
            sum += (N - 1) * val;
        }
        return sum;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(0, 1000000000);
        return dist(engine);
    }
};

#endif // ADD_DOUBLE_SUM_CHECKER_HPP
