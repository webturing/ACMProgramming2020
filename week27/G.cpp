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
    int n;
    while (cin >> n) {
        vector<pair<int, int>> a(n);
        for (auto &e:a)cin >> e.first >> e.second;
        sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) -> bool {
            return x.second < y.second;
        });
        int tot(0), start = 0;
        for (const auto &e:a) {
            if (e.first >= start) {
                ++tot;
                start = e.second;
            }
        }
        cout << tot << endl;
    }


    return 0;
}
/**
 * 1. pair<int,int>  first/second make_pair方便刻画点或者区间
 * 2. 贪心算法： 多任务安排 要按照终点排序：
 * 3. 贪心目标：一次能安排最多任务/最少多少次可以安排所有任务
 * 4. 贪心选择： 每一次选择一个最早结束的相容任务
*/