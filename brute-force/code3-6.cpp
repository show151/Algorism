#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int main() {
    int N = 11; // 配列の要素数
    int W = 55; // 作りたい合計値
    vector<int> a(N); // 配列aをN個分用意
    for (int i = 0; i < N; ++i) {
        a[i] = i; // 配列aに0からN-1までの値を順に代入
    }

    bool exist = false; // 合計Wを作れる部分集合が存在するかどうかのフラグ

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    // 全ての部分集合をビット列で表現して全探索
    for (int bit = 0; bit < (1 << N); ++bit) {
        int sum = 0; // 部分集合の合計値
        for (int i = 0; i < N; ++i) {
            // i番目の要素を部分集合に含める場合
            if (bit & (1 << i)) {
                sum += a[i];
            }
        }

        // 合計がWと一致する部分集合が見つかった場合
        if (sum == W) {
            exist = true;
            break; // ループを抜ける
        }
    }

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 結果を出力
    if (exist) {
        cout << "合計 " << W << " を作る部分集合が存在します。" << endl;
    } else {
        cout << "合計 " << W << " を作る部分集合は存在しません。" << endl;
    }
    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;

    return 0; // プログラム終了
}