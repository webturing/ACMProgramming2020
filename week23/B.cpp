#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        for (int y = 0; y <= 200; y++) {
            if ((x * 6 + y *7) >= 1200) { //用整数来避免小数的误差
                if (y & 1)
                    cout << y / 2 << ".5" << endl;
                else
                    cout << y / 2 << endl;
                break;
            }
        }
    }
    return 0;
}