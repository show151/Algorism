#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 9;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        a[i] = i+1;
    }

    int min_val = a[0];
    int max_val = a[0];
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    int max_diff = max_val - min_val;
    cout << max_diff << endl; // 出力: 5
    return 0;
}