#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define vi vector<int>
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 1000000007;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}

template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    RREP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

vector<int> getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    REP(i, 1, n) {
        z[i] = max(0LL, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i;
            y = i+z[i];
            ++z[i];
        }
    }
    return z;
}

int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    vi block(n);
    block[n-1] = n;
    RREP(i, n-2, -1) {
        if (a[i] >= a[i+1]) block[i] = i+1;
        else block[i] = block[i+1];
    }
    // cout << "BLOCK: " << to_string(block) << '\n';

    vi dp(n);
    dp[n-1] = 1;
    int best = 1;
    RREP(i, n-2, -1) {
        if (block[i] >= n) dp[i] = n-i;
        else if (block[i] == n-1) dp[i] = n-i-1;
        else {
            dp[i] = block[i]-i;
            if (a[block[i]+1] > a[block[i]-1]) dp[i] = max(dp[i], block[i] - i + block[block[i]+1]-block[i]-1);
            if (block[i]>=2 && a[block[i]] > a[block[i]-2]) dp[i] = max(dp[i], block[i] - i - 1 + block[block[i]]-block[i]);
        }
        best = max(best, dp[i]);
        // cout << i << " -> " << dp[i] << '\n';
    }
    cout << best;
}