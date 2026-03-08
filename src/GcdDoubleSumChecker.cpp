#ifndef GCDDOUBLESUMCHECKER_CPP
#define GCDDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

class GcdDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return std::gcd(x, y);
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        if (A.empty()) {
            return 0;
        }

        const T maxValue = *std::max_element(A.begin(), A.end());
        std::vector<T> count(maxValue + 1, 0);
        for (const T value : A) {
            ++count[value];
        }

        std::vector<T> exactPairCount(maxValue + 1, 0);
        T result = 0;

        for (T g = maxValue; g >= 1; --g) {
            T multipleCount = 0;
            for (T x = g; x <= maxValue; x += g) {
                multipleCount += count[x];
            }

            T pairCount = multipleCount * (multipleCount - 1) / 2;
            for (T x = g * 2; x <= maxValue; x += g) {
                pairCount -= exactPairCount[x];
            }

            exactPairCount[g] = pairCount;
            result += g * pairCount;
        }

        return result;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(1, 200000);
        return dist(engine);
    }
};

#endif // GCDDOUBLESUMCHECKER_CPP
