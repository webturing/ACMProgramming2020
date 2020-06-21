#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(const string &str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline void oo(const string &str, vector<T> val) {
    cerr << str << " ";
    for (auto e:val) {
        cerr << e << " ";
    }
    cerr << endl;
}

template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

//最容易想到的模拟算法 枚举每一个子序列O(n^3)
int max_sub_cube(vector<int> &v) {//O(n^3)
    int best = 0, n = int(v.size());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += v[k];
            }
            best = max(best, s);
        }
    return best;
}

//第一个优化，预处理前缀和，然后可以在O(1)时间内计算出子序列v[i:k] 整体时间O(n^2)
int max_sub_square(vector<int> &v) {//O(n^2)
    vector<int> b(v);
    partial_sum(b.begin(), b.end(), b.begin());//O(n)
    int best = 0, n = int(v.size());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int s = i > 0 ? b[j] - b[i - 1] : b[j];
            best = max(best, s);
        }
    return best;
}

int max_sub_linear_dp(vector<int> &v) {//O(n)
    vector<int> dp(v.size());
    dp[0] = v[0];
    for (auto i = 1; i < v.size(); i++) {
        dp[i] = max(dp[i] + v[i], v[i]);
    }
    return *max_element(dp.begin(), dp.end());
}

int max_sub_linear_greedy(vector<int> &v) {//O(n)
    int best(0), local(0);//如果数组全负有的要求返回最大值，也就一个O(n)判断 也可以用best=INT_MIN来初始化
    for (auto i = 0; i < v.size(); i++) {
        local += v[i];
        if (local < 0) {
            local = 0;
        }
        best = max(best, local);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v{3, -2, 3, -5, 4};
    cout << max_sub_cube(v) << endl;
    cout << max_sub_square(v) << endl;
    cout << max_sub_linear_dp(v) << endl;
    cout << max_sub_linear_greedy(v) << endl;
    cout << max_sub_square_dc(v) << endl;
    return 0;
}
