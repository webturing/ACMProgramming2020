#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

template<typename T>
inline void oo(string str, T val) { cerr << str << val << endl; }

template<typename T>
void OO(string s, T a) {
    cerr << s << ":";
    for (auto e:a)cerr << e << " ";
    cerr << endl;
}

template<typename T>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    FOR(cas, 0, read<int>()) {
        string s = read<string>();
        vector<LL> v;
        FOR(i, 0, s.size())v.push_back(s[i] - '0');
        int t = -1, temp = 0;
        vector<int> ans;
        FOR(i, 0, s.size()) {
            temp = temp * 10 + v[i];
            if (temp <= t)continue;
            ans.push_back(temp);
            t = ans.back();
            temp = 0;
        }
        if (temp > ans.back())
            ans.push_back(temp);
        else if (temp > 0) {
            ostringstream oss;
            oss << ans.back() << temp;
            istringstream iss(oss.str());
            iss >> ans.back();
        }
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << "," << ans[i];
        cout << endl;
    }
    return 0;
}