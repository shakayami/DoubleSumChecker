pub trait DoubleSumChecker {
    fn func(&self, x: i64, y: i64) -> i64;

    fn solve_naive_algorithm(&self, values: &[i64]) -> i64 {
        let mut ans = 0_i64;
        for i in 0..values.len() {
            for j in (i + 1)..values.len() {
                ans += self.func(values[i], values[j]);
            }
        }
        ans
    }

    fn solve_faster_algorithm(&self, values: &[i64]) -> i64;

    fn has_mismatch(&self, values: &[i64]) -> bool {
        self.solve_naive_algorithm(values) != self.solve_faster_algorithm(values)
    }
}

pub struct AddAgentChecker;

impl DoubleSumChecker for AddAgentChecker {
    fn func(&self, x: i64, y: i64) -> i64 {
        x + y
    }

    fn solve_faster_algorithm(&self, values: &[i64]) -> i64 {
        let n = values.len() as i64;
        values.iter().map(|v| (n - 1) * v).sum()
    }
}

pub struct SubAgentChecker;

impl DoubleSumChecker for SubAgentChecker {
    fn func(&self, x: i64, y: i64) -> i64 {
        x - y
    }

    fn solve_faster_algorithm(&self, values: &[i64]) -> i64 {
        values
            .iter()
            .enumerate()
            .map(|(i, v)| ((values.len() as i64 - 1) - 2 * i as i64) * v)
            .sum()
    }
}

#[cfg(test)]
mod tests {
    use super::{AddAgentChecker, DoubleSumChecker, SubAgentChecker};

    #[test]
    fn add_agent_matches_naive() {
        let checker = AddAgentChecker;
        let values = vec![1, 3, 5, 7];
        assert!(!checker.has_mismatch(&values));
    }

    #[test]
    fn sub_agent_matches_naive() {
        let checker = SubAgentChecker;
        let values = vec![10, 4, 2, 1];
        assert!(!checker.has_mismatch(&values));
    }
}
