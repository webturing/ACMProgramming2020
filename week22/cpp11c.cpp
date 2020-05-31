#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    int v[10];
    memset(v, 0, sizeof(v));//按字节清零
    fill(v, v + 10, 0);//fill算法来清零

    for (auto &e:v)cin >> e;
    sort(v, v + 10);
    for (auto e:v)cout << e << " ";
    return 0;
}