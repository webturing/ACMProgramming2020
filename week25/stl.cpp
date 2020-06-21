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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //STL
    vector<string> v(istream_iterator<string>(cin),(istream_iterator<string>()));
    //sort(v.begin(),v.end());
    sort(v.begin(),v.end(),[](string a,string b)->bool{
        return a.length()<b.length();
    });
    copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));

    for_each(v.begin(),v.end(),[](string s)->void{
        cout<<s<<endl;
    });
    return 0;
}
