from __future__ import annotations

from abc import ABC, abstractmethod
from typing import Iterable, List


class AbstractDoubleSumChecker(ABC):
    """C++版の AbstractDoubleSumChecker を踏襲した共通インターフェース。"""

    @abstractmethod
    def func(self, x: int, y: int) -> int:
        raise NotImplementedError

    def solve_naive_algorithm(self, values: Iterable[int]) -> int:
        arr: List[int] = list(values)
        ans = 0
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                ans += self.func(arr[i], arr[j])
        return ans

    @abstractmethod
    def solve_faster_algorithm(self, values: Iterable[int]) -> int:
        raise NotImplementedError

    def has_mismatch(self, values: Iterable[int]) -> bool:
        arr = list(values)
        return self.solve_naive_algorithm(arr) != self.solve_faster_algorithm(arr)
