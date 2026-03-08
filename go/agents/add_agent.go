package agents

type AddAgentChecker struct {
	BaseChecker
}

func (a AddAgentChecker) Func(x, y int64) int64 {
	return x + y
}

func (a AddAgentChecker) SolveNaiveAlgorithm(values []int64) int64 {
	return a.BaseChecker.SolveNaiveAlgorithm(values, a.Func)
}

func (a AddAgentChecker) SolveFasterAlgorithm(values []int64) int64 {
	var ans int64
	n := int64(len(values))
	for _, v := range values {
		ans += (n - 1) * v
	}
	return ans
}

func (a AddAgentChecker) HasMismatch(values []int64) bool {
	return a.SolveNaiveAlgorithm(values) != a.SolveFasterAlgorithm(values)
}
