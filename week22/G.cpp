#include<bits/stdc++.h>

using namespace std;
using ll=unsigned long long;
ll Q[30][30];

ll f(int apple, int disk) {
    if (Q[apple][disk] != 0) return Q[apple][disk];
    if (apple <= 1 or disk == 1)return Q[apple][disk] = 1;
    if (apple < disk)return Q[apple][disk] = f(apple, apple);
    //没用空盘子方案
    //至少有一个空盘子
    return Q[apple][disk] = f(apple - disk, disk) + f(apple, disk - 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        cout << f(m, n) << endl;
    }
    return 0;

}