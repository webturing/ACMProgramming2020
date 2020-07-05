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
    for (vector<int> v(3); cin >> v[0] >> v[1] >> v[2];) {
        //if (all_of(v.begin(), v.end(), [](int x) ->bool{return x == -1;}))
        if (count(v.begin(), v.end(), -1) == 3)
            break;
        auto pos = find_if(v.begin(), v.end(), [](int x) -> bool { return x <= 168; });
        if (pos == v.end()) {
            cout << "NO CRASH" << endl;
        } else {
            cout << "CRASH " << *pos << endl;
        }
    }

    return 0;
}
/**
 * 1. all_of(start,end,predict) 从[start,end)都满足谓词predict
 * 2. count
 * 3. find(start,end,k)顺序查找关键字k,返回k首次出现的位置，如果找不到返回v.end()
 * 4. find_if(start,end,predict) 顺序查找关键字k 满足谓词predict(k)=true,返回k首次出现的位置，如果找不到返回v.end()
*/