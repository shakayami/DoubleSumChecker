#ifndef SQUARESUMDOUBLESUMCHECKER_CPP
#define SQUARESUMDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class SquareSumDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return x * x + y * y;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        const int N = static_cast<int>(A.size());
        T sumSquares = 0;
        for (const auto& val : A) {
            sumSquares += val * val;
        }
        return (N - 1) * sumSquares;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(0, 1000000000);
        return dist(engine);
    }
};

#endif // SQUARESUMDOUBLESUMCHECKER_CPP
