#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<long long> memo;

// メモ化再帰を用いてフィボナッチ数列の第N項を計算する関数
long long fibo(int N) {
    if (N == 0) { // ベースケース1: Nが0なら0を返す
        return 0;
    } else if (N == 1) { // ベースケース2: Nが1なら1を返す
        return 1;
    }

    // すでに計算済みならその値を返す
    if (memo[N] != -1) {
        return memo[N];
    }

    // 未計算の場合は再帰的に計算し、結果をメモに保存
    return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main() {
    memo.assign(50, -1); // メモ配列を-1で初期化（未計算を示す）

    // 計測開始時刻を取得
    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    fibo(49); // フィボナッチ数列の第49項まで計算

    // 計算したフィボナッチ数列の各項を出力
    for (int N = 0; N < 50; ++N) {
        cout << "F[" << N << "] = " << memo[N] << endl;
    }

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;
}