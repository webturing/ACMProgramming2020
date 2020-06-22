#include<bits/stdc++.h>

using namespace std;
const int maxn = 110;
int a[maxn][maxn];
int book[maxn][maxn];
bool flag = false;
int step = 0;
struct p {
    int x;
    int y;
    int step;
};

int main() {
    int next[4][2] = {{0,  1},
                      {1,  0},
                      {0,  -1},
                      {-1, 0}};
    int n, m;
    while (cin >> n >> m) {
        memset(a, 0, sizeof(a));
        memset(book, 0, sizeof(book));
        step = 0;
        flag = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        queue<p> Q;
        p tmp = {1, 1, 0};
        Q.push(tmp);
        book[sx][sy] = 1;
        while (Q.size()) {
            p tmp = Q.front();
            int x = tmp.x, y = tmp.y;
            if (x == ex && y == ey) {
                flag = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int tx = x + next[i][0];
                int ty = y + next[i][1];
                if (tx < 1 || ty < 1 || tx > n || ty > m)
                    continue;
                if (a[tx][ty] == 0 && book[tx][ty] == 0) {
                    p t = {tx, ty, tmp.step + 1};
                    Q.push(t);
                    book[tx][ty] = 1;
                }
            }
            Q.pop();
        }
        if (flag)
            cout << Q.front().step << endl;
        else
            cout << "No Way!\n";
    }
    return 0;
}