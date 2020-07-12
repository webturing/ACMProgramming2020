#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
    for (double n, a; cin >> n >> a;) {
        double t = n * 1000 / 3600 / a;
        cout << setiosflags(ios::fixed) << setprecision(3)
             << -n * 1000 / 3600 * t / 2 << endl;
    }
    return 0;
}