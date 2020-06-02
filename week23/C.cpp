#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    map<char, int> M;
    M['H'] = 1;
    M['C'] = 12;
    M['N'] = 14;
    M['O'] = 16;
    M['F'] = 19;
    M['P'] = 31;
    M['S'] = 32;
    M['K'] = 39;
    while (T--) {
        string s;
        cin >> s;
        char ch, num;
        int tot = 0;
        for (auto c:s) {
            if (M[c]) {
                tot += M[c];
                ch = c;
            } else {
                tot += M[ch] * (c - '1');
            }
        }
        cout << tot << endl;
    }
    return 0;
}