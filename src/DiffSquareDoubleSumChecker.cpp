#ifndef DIFFSQUAREDOUBLESUMCHECKER_HPP
#define DIFFSQUAREDOUBLESUMCHECKER_HPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class DiffSquareDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return (x-y)*(x-y);
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        T result1 = 0;
        T result2 = 0;
        int N=A.size();
        for(int i=0;i<N;i++){
            result1+=A[i];
            result2+=A[i]*A[i];
        }
        return result2*N-result1*result1;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(1, 1000000);
        return dist(engine);
    }
};

#endif // DIFFSQUAREDOUBLESUMCHECKER_HPP
