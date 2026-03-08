from __future__ import annotations

from .base import AbstractDoubleSumChecker


class AddAgentChecker(AbstractDoubleSumChecker):
    def func(self, x: int, y: int) -> int:
        return x + y

    def solve_faster_algorithm(self, values):
        arr = list(values)
        n = len(arr)
        return sum((n - 1) * v for v in arr)
