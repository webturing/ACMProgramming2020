#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    vector<int> v(10);
    //  for (int i = 0; i < v.size(); i++)cin >> v[i];
    for (auto &e:v)cin >> e;//通过引用写入数据
    sort(v.begin(), v.end());
    // for (int i = 0; i < v.size(); i++)cout << v[i] << " ";
    for (auto e:v)cout << e << " ";
    return 0;
}