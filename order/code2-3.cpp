#include <iostream>
#include <chrono>
using namespace std;

int main() {
    int N = 100; // 2からNまでの偶数を出力する上限値

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    // 2からNまでの偶数を順に出力
    for (int i = 2; i <= N; i+=2) { // iを2ずつ増やしながらループ
        cout << i << endl; // 現在の偶数iを出力
    }

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;

    return 0; // プログラム終了
}