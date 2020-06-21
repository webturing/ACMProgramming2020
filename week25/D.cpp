#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<string> v(istream_iterator<string>(cin), (istream_iterator<string>()));
    for_each(v.begin(), v.end(), [](string s) {
        for_each(s.begin(), s.end(), [](char c) {
            string st;
            st.push_back(c);
            istringstream iss(st);
            int x;
            iss >> hex >> x;
            for (auto i = 3; i >= 0; i--) {
                cout << ((x >> i) & 1);
            }
        });
        cout << endl;
    });
    return 0;
}