#include<bits/stdc++.h>

using namespace std;

int main() {
    for (int n; cin >> n;) {
        vector<int> v(1, 1);
        for (int i = 2; i <= n; i++) {
            for (auto &e:v) {
                e *= i;
            }
            int carry = 0;
            for (auto &e:v) {
                e += carry;
                carry = e / 10;
                e %= 10;
            }
            while (carry > 0) {
                v.emplace_back(carry % 10);
                carry /= 10;
            }

        }
        copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout, ""));
        cout << endl;
    }
    return 0;
}