#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    int res = n * 3 + min(k - 1, n - k);
    if (res <= t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}