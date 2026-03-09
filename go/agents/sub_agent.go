package agents

type SubAgentChecker struct {
	BaseChecker
}

func (s SubAgentChecker) Func(x, y int64) int64 {
	return x - y
}

func (s SubAgentChecker) SolveNaiveAlgorithm(values []int64) int64 {
	return s.BaseChecker.SolveNaiveAlgorithm(values, s.Func)
}

func (s SubAgentChecker) SolveFasterAlgorithm(values []int64) int64 {
	var ans int64
	n := int64(len(values))
	for i, v := range values {
		ans += (n - 1 - 2*int64(i)) * v
	}
	return ans
}

func (s SubAgentChecker) HasMismatch(values []int64) bool {
	return s.SolveNaiveAlgorithm(values) != s.SolveFasterAlgorithm(values)
}
