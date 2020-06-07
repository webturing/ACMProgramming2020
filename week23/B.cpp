#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int left = 0, right = 20000000;
        while (left <= right) {
            int y = (left + right) / 2;
            int cmp = (2 * x * 3 + y * 7) - 1200;
            if (cmp == 0) {
                if (y & 1)
                    cout << y / 2 << ".5" << endl;
                else
                    cout << y / 2 << endl;
                break;
            } else if (cmp < 0) {
                left = y + 1;
            } else {
                right = y - 1;
            }
        }

    }
    return 0;
}