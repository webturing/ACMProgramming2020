#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int MAX = 0;
    string MAXstr = "";
    map<string, int> m;
    for (int i = 1; i <= n; i++) {
        string s;
        int x;
        cin >> s >> x;
        m[s] = m[s] + x;
        if (m[s] > MAX) {
            MAX = m[s];
            MAXstr = s;
        }
    }
    cout << MAXstr << endl;
}