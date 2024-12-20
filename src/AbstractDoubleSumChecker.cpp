#ifndef ABSTRACT_DOUBLE_SUM_CHECKER_CPP
#define ABSTRACT_DOUBLE_SUM_CHECKER_CPP

#include <vector>
#include <iostream>

template<typename T>
class AbstractDoubleSumChecker {
public:
    virtual ~AbstractDoubleSumChecker() = default;
 
    virtual T func(T x, T y) = 0;
    virtual T SolveNaiveAlgorithm(const std::vector<T>& A) final {
        T ans = 0;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                ans += func(A[i], A[j]);
            }
        }
        return ans;
    }
    virtual T SolveFasterAlgorithm(const std::vector<T>& A) = 0;
    virtual T RandomElementGenerator() = 0;
    virtual bool Verification(int testSize = 1000) {
        std::vector<T> A(testSize);
        for (int i = 0; i < testSize; ++i) {
            A[i] = RandomElementGenerator();
        }
        T ansNaive = SolveNaiveAlgorithm(A);
        T ansFaster = SolveFasterAlgorithm(A);
        return (ansNaive == ansFaster);
    }
};

#endif // ABSTRACT_DOUBLE_SUM_CHECKER_CPP
