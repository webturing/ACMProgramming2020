#include<bits/stdc++.h>

using namespace std;
vector<int> F;

void init(int n) {
    F.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        F[i] = i;
    }
}

int find(int x) {
    return x == F[x] ? x : (F[x] = find(F[x]));
}

bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        return false;
    }
    F[fx] = fy;
    return true;

}

int count() {
    int tot = 0;
    for (int i = 1; i < F.size(); i++) {
        if (F[i] == i)++tot;
    }
    return tot;
}

int main() {
    for (int n, m; cin >> n >> m;) {
        if (n == 0 and m == 0)break;
        init(n);
        while (m--) {
            int x, y;
            cin >> x >> y;

            merge(x, y);
        }
        cout << count() - 1 << endl;
    }


    return 0;
}