package agents

type MultiplyAgentChecker struct {
	BaseChecker
}

func (m MultiplyAgentChecker) Func(x, y int64) int64 {
	return x * y
}

func (m MultiplyAgentChecker) SolveNaiveAlgorithm(values []int64) int64 {
	return m.BaseChecker.SolveNaiveAlgorithm(values, m.Func)
}

func (m MultiplyAgentChecker) SolveFasterAlgorithm(values []int64) int64 {
	var sum int64
	var sumSquares int64
	for _, v := range values {
		sum += v
		sumSquares += v * v
	}
	return (sum*sum - sumSquares) / 2
}

func (m MultiplyAgentChecker) HasMismatch(values []int64) bool {
	return m.SolveNaiveAlgorithm(values) != m.SolveFasterAlgorithm(values)
}
