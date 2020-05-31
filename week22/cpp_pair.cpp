#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using Point=pair<int, int>;

int main() {
    Point a, b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cout << hypot(a.first - b.first, a.second - b.second);
    return 0;
}