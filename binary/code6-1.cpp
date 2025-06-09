#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

const int N = 8;
const vector<int> a = {3, 5, 8, 10, 14, 17, 21, 39};

// 二分探索でkeyの値が配列aのどこにあるかを探す関数
int binary_search(int key) {
    int left = 0; // 探索範囲の左端
    int right = (int)a.size() - 1; // 探索範囲の右端

    // leftがrightを超えるまで繰り返す
    while (left <= right) {
        int mid = left + (right - left) / 2; // 中央のインデックスを計算
        if (a[mid] == key) { // keyが見つかった場合
            return mid; 
        } else if (a[mid] < key) { // keyがmidより大きい場合
            left = mid + 1; // 探索範囲を右半分に絞る
        } else if (a[mid] > key) { // keyがmidより小さい場合
            right = mid - 1; // 探索範囲を左半分に絞る
        }
    }

    // keyが見つからなかった場合
    return -1;
}

int main() {

    // 配列aの中から指定した値を二分探索し、インデックスを出力
    cout << binary_search(10) << endl; 
    cout << binary_search(3) << endl;
    cout << binary_search(39) << endl;

    // 配列aに存在しない値を探索し、-1が返ることを確認
    cout << binary_search(-100) << endl;
    cout << binary_search(9) << endl;
    cout << binary_search(100) << endl;

    return 0; // プログラム終了
}