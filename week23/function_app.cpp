#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)


template<typename T=int>
inline void oo(const string &str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

int foo(string s) {//simple
    return 0;
}

int foo(string &s) {//内存效率高better /dangerous
    return 0;
}

int foo(const string &s) {//引用的s不能修改 best
    return 0;
}


int main() {
    ios::sync_with_stdio(false);//关闭cin/cout与scanf/printf流同步
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s = read<string>();
    cout << foo(s) << endl;
    return 0;
}
