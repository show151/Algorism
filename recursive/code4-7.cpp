#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int main() {
    vector<long long> F(50); // フィボナッチ数列を格納する配列（サイズ50）
    F[0] = 0; // フィボナッチ数列の0項目を初期化
    F[1] = 1; // フィボナッチ数列の1項目を初期化

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    // 2項目から49項目までフィボナッチ数列を計算
    for (int N = 2; N < 50; ++N) {
        F[N] = F[N - 1] + F[N - 2]; // フィボナッチ数列の漸化式

        // 現在の項番号と値を出力
        cout << "N = " << N << ", F[" << N << "] = " << F[N] << endl;
    }

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;

    return 0; // プログラム終了
}