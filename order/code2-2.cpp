#include <iostream>
#include <chrono>
using namespace std;

int main() {
    int N = 10000;

    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    int count = 0; // カウンタ変数の初期化
    // 2重ループでN*N回countをインクリメント
    for (int i = 0; i < N; ++i) { // 外側のループ（N回繰り返す）
        for (int j = 0; j < N; ++j) { // 内側のループ（N回繰り返す）
            ++count; // countを1増やす
        }
    }

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 最終的なcountの値を出力
    cout << "count: " << count << endl;
    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;

    return 0; // プログラム終了
}