#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<string> v(istream_iterator<string>(cin), (istream_iterator<string>()));
    int tot = 0;
    for_each(v.begin(), v.end(), [&tot](string s) -> bool {
        if (s.find('4') == string::npos and count_if(s.begin(), s.end(), [](char c) -> bool {
            return c == '6' or c == '8';
        }) >= 5) {
            cout << s << endl;
            ++tot;
        }
    });
    cout << tot << endl;
    return 0;
}