#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
inline void oo(const string &str, T val) { cerr << str << val << endl; }

template<typename T=int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

struct BTree {
    char root;
    BTree *left, *right;

    BTree(char root, BTree *left = nullptr, BTree *right = nullptr) : root(root), left(left), right(right) {}

    BTree(const string &pre, const string &mid) {
        if (mid.empty())return;
        if (mid.size() == 1) {
            root = mid[0];
            return;
        }
        string lmid, lpre, rmid, rpre;
        auto pos = mid.find(pre[0]);
        lmid = mid.substr(0, pos);
        rmid = mid.substr(pos + 1);
        for (int i = 1; i < pre.length(); i++) {
            if (lmid.find(pre[i]) != string::npos) {
                lpre.push_back(pre[i]);
            }
            if (rmid.find(pre[i]) != string::npos) {
                rpre.push_back(pre[i]);
            }
        }
//        cerr<<"lmid="<<lmid<<" lpre="<<lpre<<endl;
//        cerr<<"rmid="<<rmid<<" rpre="<<rpre<<endl;
        if (lmid.size())left = new BTree(lpre, lmid);
        if (rmid.size())right = new BTree(rpre, rmid);
        root = pre[0];

    }


    void post_visit() {
        if (left != nullptr)
            left->post_visit();
        if (right != nullptr)
            right->post_visit();
        cout << root;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (string mid, pre; cin >> pre >> mid;) {
        BTree btree(pre, mid);
        btree.post_visit();

    }

    return 0;
}
/**
1. 二叉树的实现
 2.构造函数的递归
 3.字符串处理，二叉树的遍历
 */