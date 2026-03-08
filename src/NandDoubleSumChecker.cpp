#ifndef NANDDOUBLESUMCHECKER_CPP
#define NANDDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class NandDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;
    static constexpr T MASK = (1LL << 30) - 1;

    T func(T x, T y) override {
        return (~(x & y)) & MASK;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        const int N = static_cast<int>(A.size());
        T result = 0;
        for (int k = 0; k < 30; ++k) {
            T ones = 0;
            for (int i = 0; i < N; ++i) {
                if ((A[i] >> k) & 1LL) {
                    ++ones;
                }
            }
            const T zeros = N - ones;
            const T pairs_and_zero = zeros * (zeros - 1) / 2 + ones * zeros;
            result += pairs_and_zero << k;
        }
        return result;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(0, 1000000000);
        return dist(engine);
    }
};

#endif // NANDDOUBLESUMCHECKER_CPP
