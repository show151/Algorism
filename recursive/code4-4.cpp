#include <iostream>
#include <chrono>
using namespace std;

// 2つの整数mとnの最大公約数（GCD）をユークリッドの互除法で再帰的に計算する関数
int GCD(int m, int n) {
    if (n == 0) { // nが0になったらmが最大公約数
        return m;
    }

    // nが0でない場合、GCD(n, m % n)を再帰的に計算
    return GCD(n, m % n);
}

int main() {

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    // 51と15の最大公約数を計算して出力
    cout << GCD(51, 15) << endl;
    // 15と51の最大公約数を計算して出力
    cout << GCD(15, 51) << endl;

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;

    return 0; // プログラム終了
}