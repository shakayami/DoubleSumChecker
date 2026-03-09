package agents

import "testing"

func TestAddAgent(t *testing.T) {
	agent := AddAgentChecker{}
	data := []int64{1, 2, 3, 4}
	if agent.HasMismatch(data) {
		t.Fatalf("add agent mismatch")
	}
}

func TestSubAgent(t *testing.T) {
	agent := SubAgentChecker{}
	data := []int64{10, 4, 2, 1}
	if agent.HasMismatch(data) {
		t.Fatalf("sub agent mismatch")
	}
}

func TestMultiplyAgent(t *testing.T) {
	agent := MultiplyAgentChecker{}
	data := []int64{2, 3, 5, 7}
	if agent.HasMismatch(data) {
		t.Fatalf("multiply agent mismatch")
	}
}
