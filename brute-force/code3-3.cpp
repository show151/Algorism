#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
const int INF = 20000000;

int main() {
    int N = 1000000; // 配列の要素数
    vector<int> a(N); // 配列aをN個分用意
    for (int i = 0; i < N; ++i) {
        a[i] = i; // 配列aに0からN-1までの値を順に代入
    }

    int min_value = INF; // 最小値を格納する変数（初期値は十分大きい値）

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    // 配列aの中から最小値を探す
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_value) { // より小さい値が見つかった場合
            min_value = a[i];   // 最小値を更新
        }
    }

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 最小値を出力
    cout << "最小値: " << min_value << endl;
    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;

    return 0; // プログラム終了
}