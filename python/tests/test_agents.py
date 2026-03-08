import unittest

from doublesum.add_agent import AddAgentChecker
from doublesum.sub_agent import SubAgentChecker


class AgentTest(unittest.TestCase):
    def test_add_agent_matches_naive(self):
        checker = AddAgentChecker()
        data = [1, 3, 5, 7]
        self.assertEqual(checker.solve_naive_algorithm(data), checker.solve_faster_algorithm(data))

    def test_sub_agent_matches_naive(self):
        checker = SubAgentChecker()
        data = [10, 4, 2, 1]
        self.assertEqual(checker.solve_naive_algorithm(data), checker.solve_faster_algorithm(data))


if __name__ == '__main__':
    unittest.main()
