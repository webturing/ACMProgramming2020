#include<bits/stdc++.h>

using namespace std;

int main() {
    for (string line; cin >> line;) {
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        cout << line << endl;
    }

    return 0;
}