#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    ll n;
    while (cin >> n) {
        if (n == 1) {
            cout << "Wrong" << endl;
            continue;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        while (n % 2 == 0) {
            n /= 2;
        }
        if (n == 1) {
            cout << "Accepted" << endl;

        } else {
            cout << "Wrong" << endl;
        }

    }

    return 0;
}