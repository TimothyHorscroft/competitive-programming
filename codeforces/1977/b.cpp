#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int x;
        cin >> x;
        vi res;
        while (x) {
            if (x % 2 == 0) res.push_back(0);
            else if (x % 4 == 1) res.push_back(1);
            else {
                res.push_back(-1);
                ++x;
            }
            x /= 2;
        }
        cout << res.size() << '\n';
        for (int i : res) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}