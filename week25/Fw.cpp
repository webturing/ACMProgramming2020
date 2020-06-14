#include<bits/stdc++.h>

using namespace std;

int inv(const string &s) {
    int tot(0);
    for (size_t i = 0; i < s.size(); i++) {
        for (size_t j = i + 1; j < s.size(); j++) {
            if (s[i] > s[j]) {
                ++tot;
            }
        }
    }
    return tot;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v(istream_iterator<string>(cin), (istream_iterator<string>()));
    sort(v.begin(), v.end(), [](string &a, string &b) -> bool {
        return inv(a) < inv(b) || inv(a) == inv(b) && a < b;
    });
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}