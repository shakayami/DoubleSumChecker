# DoubleSumChecker

参考記事: https://shakayami.hatenablog.com/entry/2021/01/01/044946

## 現在の実装状況
- C++ 実装: `list.txt` にある 13 種類（Add/Sub/Multiply/Const/Projection/DiffSquare/Min/Max/DiffAbs/Xor/And/Or/SquareSum/SumSquare）
- C++ 単体テスト: `tests/` に各実装ごとのテストを用意
- CI: GitHub Actions で CMake + CTest を実行

## 今後のタスク分解（全制覇に向けたロードマップ）

### Phase 1: C++ 基盤の安定化
1. CMake/CTest を唯一のテスト実行経路として固定
2. `list.txt` と `tests/` の整合性チェックを追加（欠落テスト検出）
3. 失敗時に最小反例が分かるよう、テスト出力を改善

### Phase 2: 問題網羅（C++）
1. 参考記事にある式変形パターンを表形式で列挙
2. 未実装パターンを `src/` に追加
3. 同数のテストを `tests/` に追加して回帰防止

### Phase 3: 多言語展開（競技プログラミング主要言語）
対象候補:
- Python
- Rust
- Go
- Java
- Kotlin

進め方:
1. 各言語で「同一I/O仕様」の CLI を作成
2. 共通テストベクトル（JSON/TSV）を定義
3. 言語ごとにラッパーを用意して同一ケースで検証

### Phase 4: マルチ言語 CI
1. GitHub Actions のジョブを言語別に分離（失敗箇所を明確化）
2. 共通テストデータで C++/Python/Rust/Go/Java/Kotlin を横断実行
3. 実行時間短縮のためキャッシュ（pip/cargo/go build/maven）を導入

### Phase 5: 品質強化
1. ランダムテスト（プロパティベーステスト）を追加
2. ベンチマークを導入して競プロ制約を満たすことを確認
3. ドキュメントに「実装済み/未実装マトリクス」を公開
