#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 100;
    int v = 10; 
    int count = 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        a[i]=i;
    }
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}