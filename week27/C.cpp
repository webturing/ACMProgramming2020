#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(const string &str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (string s, t; cin >> s >> t;) {
        size_t tot = 0, pos = 0;
        for (; (pos = s.find(t, pos)) != string::npos; pos += t.size()) {
            ++tot;
        }
        cout << tot << endl;
    }

    return 0;
}
/**
 * 字符串查找（匹配函数） s.find(t)返回是第一次出现子串t的位置(unsigned int) 如果找不到返回string::npos 有符号整数值为-1
 * 字符串查找（匹配函数） s.find(t,pos)返回是从pos开始第一次出现子串t的位置(unsigned int) 如果找不到返回string::npos 有符号整数值为-1
 * 统计单词次数的时候要越过已经匹配的部分pos+=t.size()
*/