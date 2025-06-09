#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 10個の整数を持つ配列aを初期化
    vector<int> a = {4, 3, 12, 7, 11, 1, 9, 8, 14, 6}; 

    // 配列aの0番目の要素を出力
    cout << a[0] << endl; 

    // 配列aの2番目の要素を出力
    cout << a[2] << endl; 

    // 配列aの2番目の要素を5に書き換え
    a[2] = 5; 

    // 書き換えた後の2番目の要素を出力
    cout << a[2] << endl; 
}