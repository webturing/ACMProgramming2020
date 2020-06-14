#include<bits/stdc++.h>

using namespace std;


int main() {
    size_t n;
    cin >> n;
    vector<int> v(n);
    for (auto &e:v)cin >> e;
    int best = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum < 0) {
            sum = 0;
        }
        sum += v[i];
        best = max(sum, best);
    }
    cout << best << endl;
    return 0;
}