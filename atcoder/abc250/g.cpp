#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    int res = accumulate(a.begin(), a.end(), 0LL);
    
    priority_queue<int,vi,greater<int>> pq;
    FOR(i, 0, n) {
        pq.push(a[i]);
        pq.push(a[i]);
        res -= pq.top();
        pq.pop();
    }
    cout << res;
}