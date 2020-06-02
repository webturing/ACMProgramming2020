#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const double pi = acos(-1);

int main() {
    int a[] = {5, 4, 3, 2, 1, 9, 8, 7, 6};
    int d[360] = {0};
    for (int i = 0; i < 9; i++) {
        int start = -90 + i * 40;
        int end = start + 40;
        for (int j = (start + 360) % 360; j != (end + 360) % 360; j = (j + 1) % 360) {
            d[j] = a[i];
        }
    }
//    for (int i = 0; i < 360; i++)
//        cout << d[i];
//    cout << endl;
    for (int x, y, x1, y1; cin >> x >> y >> x1 >> y1;) {
        double dy = y1 - y;
        double dx = x1 - x;
        int quad = 1;
        if (dx >= 0 and dy >= 0)quad = 1;
        if (dx >= 0 and dy <= 0)quad = 4;
        if (dx <= 0 and dy >= 0)quad = 2;
        if (dx <= 0 and dy <= 0)quad = 3;
        double dg = atan(dy / dx);
        int deg = fmod(dg / pi * 180 + 360, 360);

        if (quad >= 3 and deg < 180)deg = 360 - deg;
        if (quad <= 2 and deg > 180)deg = 360 - deg;
       // cout << "quad=" << quad << ",deg=" << deg << endl;
        cout << d[deg] << endl;

    }

    return 0;
}