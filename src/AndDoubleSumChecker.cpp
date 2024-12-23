#ifndef ANDDOUBLESUMCHECKER_CPP
#define ANDDOUBLESUMCHECKER_CPP

#include "AbstractDoubleSumChecker.cpp"
#include <random>

class AndDoubleSumChecker : public AbstractDoubleSumChecker<long long> {
    using T = long long;

    T func(T x, T y) override {
        return x&y;
    }

    T SolveFasterAlgorithm(const std::vector<T>& A) override {
        int N=A.size();
        T result = 0;
        for(int k=0;k<63;k++){
            long long int X=0;
            long long int Y=0;
            for(int i=0;i<N;++i){
                if ((A[i]>>k)&1){
                    X++;
                }
                else{
                    Y++;
                }
            }
            result+=(X*(X-1)/2)<<k;
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

#endif // ANDDOUBLESUMCHECKER_CPP
