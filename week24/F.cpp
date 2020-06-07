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

string dec2bin(int n) {
    string s;
    for (int i = 7; i >= 0; i--) {
        if ((n >> i) & 1)s.push_back('1');
        else s.push_back('0');
    }
    return s;
}


int bin2dec(string b) {
    int s = 0;
    for (auto c:b) {
        s = s * 2 + c - '0';
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (string s; cin >> s;) {
        if (s.find('.') != string::npos) {
            int a, b, c, d;
            for (auto &c:s)if (c == '.')c = ' ';
            istringstream iss(s);
            iss >> a >> b >> c >> d;
            cout << dec2bin(a) << dec2bin(b) << dec2bin(c) << dec2bin(d) << endl;
        } else {
            int a = bin2dec(s.substr(0, 8));
            int b = bin2dec(s.substr(8, 8));
            int c = bin2dec(s.substr(16, 8));
            int d = bin2dec(s.substr(24, 8));
            cout << a << "." << b << "." << c << "." << d << endl;
        }
    }


    return 0;
}
