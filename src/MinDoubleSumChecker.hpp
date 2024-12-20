#ifndef MINDOUBLESUMCHECKER_HPP
#define MINDOUBLESUMCHECKER_HPP

#include "AbstractDoubleSumChecker.hpp"
#include <random>
#include <algorithm>

class MinDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return std::min(x,y);
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        T result = 0;
        int N=A.size();
        std::vector<T> A_copy(N);
        std::copy(A.begin(),A.end(),A_copy.begin());
        std::sort(A_copy.begin(),A_copy.end());
        for(int i=0;i<N;++i){
            result+=(N-1-i)*A_copy[i];
        }

        return result;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(1, 100);
        return dist(engine);
    }
};

#endif // MINDOUBLESUMCHECKER_HPP
