#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define print(x) cout << to_string(x) << '\n'
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
 
int INF = 1LL<<60;
int MOD = 1e9+7;
 
string to_string(char &c) {string x(1, c); return x;}
string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
string to_string(vb &v) {
    string res;
    for (const bool &x : v) res += to_string(x) + ' ';
    return res;
}
template <class C> string to_string(C &v) {
    string res;
    for (auto &x : v) res += to_string(x) + ' ';
    return res;
}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {
    for (auto &x : v) is >> x;
    return is;
}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> pr) {
    os << '(' << pr.first << ", " << pr.second << ')';
    return os;
}
ostream &operator<<(ostream &os, char &c) {os << (char)c; return os;}
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
ostream &operator<<(ostream &os, vb &v) {
    bool first = true;
    os << '[';
    for (const bool &x : v) {
        if (!first) os << ',' << ' ';
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
template <class C> ostream &operator<<(ostream &os, C &v) {
    bool first = true;
    os << '[';
    for (auto &x : v) {
        if (!first) os << ',' << ' ';
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
string bin_string(int x) {
    const int d = 6;
    string res(d, ' ');
    REP(i, 0, d) res[d-1-i] = '0'+(x>>i & 1LL);
    return res;
}
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}
 
main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m));
    REP(i, 0, n) REP(j, 0, m) cin >> grid[i][j];
    
    int k=-1;
    for (int b=MOD; b>=1; b/=2) {
        while (k+b<=MOD) {
            vb masks(1<<m);
            REP(r, 0, n) {
                int mask = 0;
                REP(c, 0, m) {
                    if (grid[r][c] >= k+b) mask |= 1<<c;
                }
                masks[mask] = true;
            }
            bool failed = true;
            REP(i, 0, 1<<m) if (masks[i]) {
                int nm = 0;
                REP(p, 0, m) {
                    if (!(i>>p&1)) nm |= 1<<p;
                }
                for (int j=i; ; j=(j-1)&i) {
                    if (masks[j|nm]) {
                        failed = false;
                        break;
                    }
                    if (j==0) break;
                }
            }
            if (failed) break;
            k += b;
        }
    }
    mii masks;
    REP(r, 0, n) {
        int mask = 0;
        REP(c, 0, m) {
            if (grid[r][c] >= k) mask |= 1<<c;
        }
        masks[mask] = r;
    }
    for (pii pr1 : masks) for (pii pr2 : masks) {
        if (pr2.first == (1<<m)-1) {
            cout << pr2.second+1 << " 1";
            return 0;
        }
        if ((pr1.first|pr2.first) == (1<<m)-1 && pr1.second != pr2.second) {
            cout << pr1.second+1 << ' ' << pr2.second+1;
            return 0;
        }
    }
}