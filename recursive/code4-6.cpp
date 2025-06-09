#include <iostream>  // 標準入出力ストリームを使用するためのヘッダ
#include <chrono>    // 時間計測のためのヘッダ
using namespace std;

// フィボナッチ数列の第N項を再帰的に計算する関数
int fibo(int N) {
    cout << "N = " << N << endl; // 現在のNの値を出力

    if (N == 0) { // ベースケース1: Nが0なら0を返す
        return 0;
    } else if (N == 1) { // ベースケース2: Nが1なら1を返す
        return 1;
    }

    // 再帰呼び出しでfibo(N-1)とfibo(N-2)を計算し、その和をresultに格納
    int result = fibo(N - 1) + fibo(N - 2);
    cout << "N = " << N << ", result = " << result << endl; // 現在のNと計算結果を出力

    return result; // 計算結果を返す
}

int main() {

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    fibo(6); // フィボナッチ数列の第6項を計算

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;

    return 0; // プログラム終了
}