#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    for (string s; getline(cin, s);) {
        istringstream iss(s);
        stack<ll> S;
        for (string tk; iss >> tk;) {
            if (tk == "+" || tk == "-" || tk == "*" || tk == "/") {
                ll b = S.top();
                S.pop();
                ll a = S.top();
                S.pop();
                if (tk == "+") {
                    S.push(a + b);
                }
                if (tk == "-") {
                    S.push(a - b);
                }
                if (tk == "*") {
                    S.push(a * b);
                }
                if (tk == "/") {
                    S.push(a / b);
                }
            } else {
                istringstream iss2(tk);
                ll m;
                iss2 >> m;
                S.push(m);
            }

        }
        cout << S.top() << endl;
    }
    return 0;
}