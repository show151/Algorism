#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int main() {
    int N = 1000000; // 配列の要素数
    int v = 0;       // 探索する値
    vector<int> a(N); // 配列aをN個分用意

    // 配列aに0からN-1までの値を順に代入
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }

    bool exist = false; // vが配列に存在するかどうかのフラグ
    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻
    // 線形探索で配列aの中にvがあるか調べる
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) { // vが見つかった場合
            exist = true;
            break; // ループを抜ける
        }
    }

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 探索結果を出力
    if (exist) {
        cout << "値 " << v << " は配列に存在します。" << endl;
    } else {
        cout << "値 " << v << " は配列に存在しません。" << endl;
    }
    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;
    

    return 0; // プログラム終了
}