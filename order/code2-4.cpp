#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;

double calc_dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int N = 10000;
    vector<double> x(N), y(N);

    double miniumum_dist = 100000000.0;

    auto start = chrono::high_resolution_clock::now(); // 開始時刻

    for (int i = 0; i < N; ++i) { // i番目の点を選ぶループ
        for (int j = i + 1; j < N; ++j) { // iより後ろの点jを選ぶループ
            // 点iと点jのユークリッド距離を計算
            double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);
            // これまでの最小距離より小さければ更新
            if (dist_i_j < miniumum_dist) {
                miniumum_dist = dist_i_j;
            }
        }
    }

    // 計測終了時刻を取得
    auto end = chrono::high_resolution_clock::now(); // 終了時刻
    // 経過時間（秒）を計算
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();

    // 最小距離を出力
    cout << "最小距離: " << miniumum_dist << endl;
    // 実行時間（秒）を出力
    cout << "実行時間: " << duration << " 秒" << endl;

    return 0; // プログラム終了
}