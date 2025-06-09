#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 100;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        a[i]=i;
    }

    int min1, min2;
    // 最初の2つで初期化
    if (a[0] < a[1]) {
        min1 = a[0];
        min2 = a[1];
    } else {
        min1 = a[1];
        min2 = a[0];
    }

    for (int i = 2; i < N; ++i) {
        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        } else if (a[i] < min2) {
            min2 = a[i];
        }
    }
    cout << min2 << endl;
    return 0;
}