#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const double pi = acos(-1);

int main() {

    for (int x, y, x1, y1; cin >> x >> y >> x1 >> y1;) {
        x1 -= x, y1 -= y;
        double R = asin(y1 / sqrt((x1 * x1) + (y1 * y1)));
        if (x1 < 0) R = -R - pi;
        int c = R * 360 / 2 / pi;
        cout << (110 - c) % 360 / 40 + 1 << endl;

    }

    return 0;
}