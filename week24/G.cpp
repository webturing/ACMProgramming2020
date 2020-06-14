#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
ULL pown(ULL a, ULL n, int mod){
    if(a == 0)return 0;
    if(a == 1 || n == 0) return 1;
    if(n == 1)return a%mod;
    ULL t = pown(a, n / 2, mod);
    if(n % 2 == 0){
        return t * t % mod;
    }else{
        return t * t % mod * a % mod;
    }
}
int main(){
    ULL a, b, c, d;
    int m;
    cin >> a >> b >> c >> d >> m;
    a = a % m;
    b = b % m;
    a = a * b % m;
    c *= d;
    cout << pown(a, c, m) << endl;
    return 0;
}