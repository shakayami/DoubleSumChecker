# Pattern Matrix (DoubleSumChecker)

`\sum_{0 \le i < j < N} f(A_i, A_j)` を高速化する既知パターンの一覧です。

| Pattern | `f(x, y)` | 実装 | テスト | 状態 |
|---|---|---|---|---|
| Add | `x + y` | `src/AddDoubleSumChecker.cpp` | `tests/test_AddDoubleSumChecker.cpp` | ✅ 実装済み |
| Sub | `x - y` | `src/SubDoubleSumChecker.cpp` | `tests/test_SubDoubleSumChecker.cpp` | ✅ 実装済み |
| Multiply | `x * y` | `src/MultiplyDoubleSumChecker.cpp` | `tests/test_MultiplyDoubleSumChecker.cpp` | ✅ 実装済み |
| Const | `1` | `src/ConstDoubleSumChecker.cpp` | `tests/test_ConstDoubleSumChecker.cpp` | ✅ 実装済み |
| Projection | `y` | `src/ProjectionDoubleSumChecker.cpp` | `tests/test_ProjectionDoubleSumChecker.cpp` | ✅ 実装済み |
| DiffSquare | `(x - y)^2` | `src/DiffSquareDoubleSumChecker.cpp` | `tests/test_DiffSquareDoubleSumChecker.cpp` | ✅ 実装済み |
| Min | `min(x, y)` | `src/MinDoubleSumChecker.cpp` | `tests/test_MinDoubleSumChecker.cpp` | ✅ 実装済み |
| Max | `max(x, y)` | `src/MaxDoubleSumChecker.cpp` | `tests/test_MaxDoubleSumChecker.cpp` | ✅ 実装済み |
| DiffAbs | `\|x - y\|` | `src/DiffAbsDoubleSumChecker.cpp` | `tests/test_DiffAbsDoubleSumChecker.cpp` | ✅ 実装済み |
| Xor | `x ^ y` | `src/XorDoubleSumChecker.cpp` | `tests/test_XorDoubleSumChecker.cpp` | ✅ 実装済み |
| And | `x & y` | `src/AndDoubleSumChecker.cpp` | `tests/test_AndDoubleSumChecker.cpp` | ✅ 実装済み |
| Or | `x \| y` | `src/OrDoubleSumChecker.cpp` | `tests/test_OrDoubleSumChecker.cpp` | ✅ 実装済み |
| Nand | `~(x & y)`（30bit mask） | `src/NandDoubleSumChecker.cpp` | `tests/test_NandDoubleSumChecker.cpp` | ✅ 実装済み |
| Nor | `~(x \| y)`（30bit mask） | `src/NorDoubleSumChecker.cpp` | `tests/test_NorDoubleSumChecker.cpp` | ✅ 実装済み |
| Gcd | `gcd(x, y)` | `src/GcdDoubleSumChecker.cpp` | `tests/test_GcdDoubleSumChecker.cpp` | ✅ 実装済み |
| Equal | `[x == y]` | `src/EqualDoubleSumChecker.cpp` | `tests/test_EqualDoubleSumChecker.cpp` | ✅ 実装済み |
| SquareSum | `x^2 + y^2` | `src/SquareSumDoubleSumChecker.cpp` | `tests/test_SquareSumDoubleSumChecker.cpp` | ✅ 実装済み |
| SumSquare | `(x + y)^2` | `src/SumSquareDoubleSumChecker.cpp` | `tests/test_SumSquareDoubleSumChecker.cpp` | ✅ 実装済み |

## 次に進める作業

Phase 2 の残タスク:
1. 参考記事の追加パターン（もし未収録があれば）を洗い出す
2. `src/` に実装を追加
3. `tests/` に対応テストを追加
