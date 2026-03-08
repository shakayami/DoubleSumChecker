package agents

type Checker interface {
	Func(x, y int64) int64
	SolveNaiveAlgorithm(values []int64) int64
	SolveFasterAlgorithm(values []int64) int64
	HasMismatch(values []int64) bool
}

type BaseChecker struct{}

func (b BaseChecker) SolveNaiveAlgorithm(values []int64, f func(int64, int64) int64) int64 {
	var ans int64
	for i := 0; i < len(values); i++ {
		for j := i + 1; j < len(values); j++ {
			ans += f(values[i], values[j])
		}
	}
	return ans
}
