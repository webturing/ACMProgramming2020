#include<bits/stdc++.h>

using namespace std;
//1 1 1 1
//1 2 3 4
//1 3 6 10
// partial_sum


int main() {
    int n;
    cin >> n;
    //int a[n];//discourage
    vector<int> a(n, 1);
    for (int i = 0; i < 5; i++) {
        partial_sum(a.begin(), a.end(), a.begin());
        for (auto e:a)cout << e << " ";
        cout<<endl;
    }
    return 0;
}