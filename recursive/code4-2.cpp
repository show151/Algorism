#include <iostream>  // 標準入出力ストリームを使用するためのヘッダ
#include <chrono>    // 時間計測のためのヘッダ
using namespace std;

// 再帰的に1からNまでの合計を計算する関数
int func(int N) {
    cout << "N = " << N << endl; // 現在のNの値を出力

    if (N == 0) { // ベースケース：Nが0になったら0を返す
        return 0;
    }

    // 再帰呼び出しでN-1までの合計を計算し、Nを加算
    int result = N + func(N - 1);
    cout << "N = " << N << ", result = " << result << endl; // 現在のNと計算結果を出力

    return result; // 合計値を返す
}

int main() {

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    func(20); // 1から20までの合計を再帰的に計算

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;
    
    return 0; // プログラム終了
}