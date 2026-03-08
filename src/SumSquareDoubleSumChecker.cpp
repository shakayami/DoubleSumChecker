#ifndef SUMSQUAREDOUBLESUMCHECKER_CPP
#define SUMSQUAREDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class SumSquareDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return (x + y) * (x + y);
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        const int N = static_cast<int>(A.size());
        T sum = 0;
        T squareSum = 0;
        for (const auto& val : A) {
            sum += val;
            squareSum += val * val;
        }
        return (N - 2) * squareSum + sum * sum;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(0, 1000000);
        return dist(engine);
    }
};

#endif // SUMSQUAREDOUBLESUMCHECKER_CPP
