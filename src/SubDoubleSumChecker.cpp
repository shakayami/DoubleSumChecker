#ifndef SUBDOUBLESUMCHECKER_CPP
#define SUBDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class SubDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return x-y;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        T result = 0;
        int N=A.size();
        for(int i=0;i<N;++i){
            result+=(N-2*i-1)*A[i];
        }
        return result;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(1, 1000000000);
        return dist(engine);
    }
};

#endif // SUBDOUBLESUMCHECKER_CPP
