#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 and b == 0) {//&& and ||or ! not
            break;
        }
        int c = (a + b) % 7;
        if (c == 0)c = 7;
        cout << c << endl;
    }
    return 0;
}