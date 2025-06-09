#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
const int INF = 20000000;

int main() {
    int N = 100000; // 配列の要素数
    int K = 100;    // 条件となる値
    vector<int> a(N), b(N); // 2つの配列a, bをN個分用意
    for (int i = 0; i < N; ++i) {
        a[i] = i; // 配列aに0からN-1までの値を順に代入
        b[i] = i; // 配列bに0からN-1までの値を順に代入
    }

    int min_value = INF; // 最小値を格納する変数（初期値は十分大きい値）

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    // 2重ループでa[i] + b[j]がK以上となる最小値を探す
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i] + b[j] < K) { // K未満ならスキップ
                continue;
            }

            // K以上かつ現在の最小値より小さい場合はmin_valueを更新
            if (a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
                break; // それ以上小さい値はないので内側ループを抜ける
            }
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