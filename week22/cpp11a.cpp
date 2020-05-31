#include<bits/stdc++.h>

using namespace std;
#define N 10
const int M = 10;//常量定义的方法

#define int64 long long
typedef long long int64;
using ll=long long;//C++11 风格
void ref() {
    int x = 3;
    int &y = x;//y是x的一个别名
    y++;
    cout << x << endl;
}

int main() {
    ll x = 10;
    auto z = x * x;
    return 0;
}