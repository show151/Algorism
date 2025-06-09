#include <iostream>  // 標準入出力ストリームを使用するためのヘッダ
#include <chrono>    // 時間計測のためのヘッダ
using namespace std;

int main() {
    int N = 10000000; // ループの回数（1千万回）

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    int count = 0; // カウンタ変数の初期化
    // N回ループしてcountをインクリメント
    for (int i = 0; i < N; ++i) {
        ++count; // countを1増やす
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