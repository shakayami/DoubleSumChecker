#ifndef PROJECTION_DOUBLE_SUM_CHECKER_HPP
#define PROJECTION_DOUBLE_SUM_CHECKER_HPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class ProjectionDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return y;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        int N = A.size();
        T ans=0;
        for(int i=0;i<N;++i){
            ans+=i*A[i];
        }
        return ans;
    }

    T RandomElementGenerator() override {
        static std::random_device seed_gen;
        static std::mt19937 engine(seed_gen());
        std::uniform_int_distribution<T> dist(0, 1000000000);
        return dist(engine);
    }
};

#endif // PROJECTION_DOUBLE_SUM_CHECKER_HPP
