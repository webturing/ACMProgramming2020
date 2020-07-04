#include<bits/stdc++.h>
using namespace std;
struct stu {
    double a, b, c, d, e, f, g;
    string s;
}
        k[50];
bool q(stu A, stu B) {
    if (A.g != B.g) {
        return A.g > B.g;
    }
    else {
        return A.s < A.s;
    }
}
int main() {
    int x, y, z, r, p, j, i = 0, t = 1;
    cin >> x >> y >> z >> r >> p;
    while (cin >> k[i].s >> k[i].a >> k[i].b >> k[i].c >> k[i].d >> k[i].e) {
        k[i].f = k[i].a + k[i].b + k[i].c + k[i].d;
        k[i].g = k[i].f * 0.6 + k[i].e * 0.4;
        if (k[i].a >= x && k[i].b >= y && k[i].c >= z && k[i].d >= r && k[i].f >= p) {
            i++;
        }
    }
    sort(k, k + i, q);
    for (j = 0; j < i; j++) {
        printf("%s %.f %.f %.1f %d\n", k[j].s.c_str(), k[j].f, k[j].e, k[j].g, t++);
    }
    return 0;
}
