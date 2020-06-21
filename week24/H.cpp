#include <bits/stdc++.h>

using namespace std;

int maxSum(int a[], int n) {
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt > 0) {
            cnt += a[i];
        } else {
            cnt = a[i];
        }
        res = max(res, cnt);
    }
    return res;
}

int main() {
    int n, x;
    cin >> n >> x;
    int res = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (x < 0) {
        int b = 0, e = 0, max_b = 0, max_e = 0;
        int cnt = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (cnt < 0) {
                cnt += a[i];
                if (cnt <= res) {
                    res = cnt;
                    max_e = i + 1;
                    max_b = b;
                }
            } else {
                cnt = a[i];
                b = i;
                if (cnt <= res) {
                    res = cnt;
                    max_e = i + 1;
                    max_b = b;
                }
            }
        }
        if (res < 0) {
            for (int i = max_b; i < max_e; i++) {
                a[i] *= x;
            }
        }
        res = maxSum(a, n);
    } else {
        res = maxSum(a, n) * x;
    }
    cout << res << endl;
}