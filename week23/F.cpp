#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    vector<ll> v(3, 0);
    while(cin>>v[0]>>v[1]>>v[2]) {
        sort(v.begin(), v.end());
        cout << v[1] << endl;
    }
    return 0;
}