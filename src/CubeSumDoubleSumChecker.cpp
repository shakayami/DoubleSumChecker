#ifndef CUBESUMDOUBLESUMCHECKER_CPP
#define CUBESUMDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class CubeSumDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return x * x * x + y * y * y;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        const int N = static_cast<int>(A.size());
        T sumCubes = 0;
        for (const auto& val : A) {
            sumCubes += val * val * val;
        }
        return (N - 1) * sumCubes;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(0, 10000);
        return dist(engine);
    }
};

#endif // CUBESUMDOUBLESUMCHECKER_CPP
