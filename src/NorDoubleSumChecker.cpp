#ifndef NORDOUBLESUMCHECKER_CPP
#define NORDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class NorDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;
    static constexpr T MASK = (1LL << 30) - 1;

    T func(T x, T y) override {
        return (~(x | y)) & MASK;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        const int N = static_cast<int>(A.size());
        T result = 0;
        for (int k = 0; k < 30; ++k) {
            T zeros = 0;
            for (int i = 0; i < N; ++i) {
                if (((A[i] >> k) & 1LL) == 0) {
                    ++zeros;
                }
            }
            const T pairs_or_zero = zeros * (zeros - 1) / 2;
            result += pairs_or_zero << k;
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

#endif // NORDOUBLESUMCHECKER_CPP
