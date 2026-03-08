#ifndef EQUALDOUBLESUMCHECKER_CPP
#define EQUALDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>
#include <unordered_map>

class EqualDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return x == y ? 1 : 0;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        std::unordered_map<T, T> frequency;
        frequency.reserve(A.size() * 2);

        for (const T value : A) {
            ++frequency[value];
        }

        T result = 0;
        for (const auto& [value, count] : frequency) {
            (void)value;
            result += count * (count - 1) / 2;
        }
        return result;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(1, 400);
        return dist(engine);
    }
};

#endif // EQUALDOUBLESUMCHECKER_CPP
