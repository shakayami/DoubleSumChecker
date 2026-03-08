#ifndef ABSTRACT_DOUBLE_SUM_CHECKER_CPP
#define ABSTRACT_DOUBLE_SUM_CHECKER_CPP

#include <vector>
#include <iostream>
#include <sstream>

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

    bool HasMismatch(const std::vector<T>& A, T* ansNaive = nullptr, T* ansFaster = nullptr) {
        T naive = SolveNaiveAlgorithm(A);
        T faster = SolveFasterAlgorithm(A);
        if (ansNaive) {
            *ansNaive = naive;
        }
        if (ansFaster) {
            *ansFaster = faster;
        }
        return naive != faster;
    }

    std::vector<T> MinimizeCounterExample(const std::vector<T>& source) {
        std::vector<T> current = source;
        bool changed = true;
        while (changed && current.size() > 2) {
            changed = false;
            for (size_t i = 0; i < current.size(); ++i) {
                std::vector<T> candidate;
                candidate.reserve(current.size() - 1);
                for (size_t j = 0; j < current.size(); ++j) {
                    if (j != i) {
                        candidate.push_back(current[j]);
                    }
                }
                if (HasMismatch(candidate)) {
                    current = std::move(candidate);
                    changed = true;
                    break;
                }
            }
        }
        return current;
    }

    std::string FormatArray(const std::vector<T>& A) {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < A.size(); ++i) {
            if (i > 0) {
                oss << ", ";
            }
            oss << A[i];
        }
        oss << "]";
        return oss.str();
    }

    virtual bool Verification(int testSize = 1000) {
        std::vector<T> A(testSize);
        for (int i = 0; i < testSize; ++i) {
            A[i] = RandomElementGenerator();
        }

        T ansNaive = 0;
        T ansFaster = 0;
        if (!HasMismatch(A, &ansNaive, &ansFaster)) {
            return true;
        }

        const std::vector<T> minimized = MinimizeCounterExample(A);
        T minNaive = 0;
        T minFaster = 0;
        HasMismatch(minimized, &minNaive, &minFaster);

        std::cerr << "Verification mismatch detected.\n"
                  << "  original size: " << A.size() << "\n"
                  << "  minimized size: " << minimized.size() << "\n"
                  << "  minimized input: " << FormatArray(minimized) << "\n"
                  << "  naive answer: " << minNaive << "\n"
                  << "  faster answer: " << minFaster << std::endl;
        return false;
    }
};

#endif // ABSTRACT_DOUBLE_SUM_CHECKER_CPP
