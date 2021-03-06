#include <bits/stdc++.h>
using namespace std;

#define int long long
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define print(x) cout << to_string(x) << ' '
#define println(x) cout << to_string(x) << '\n'
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)

int INF = 1LL<<60;
int MOD = 998244353;

string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
template <class C> string to_string(C &v) {
    string res;
    for (auto &i : v) res += to_string(i) + ' ';
    return res; 
}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {for (auto &x : v) is >> x; return is;}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &v);
template <typename A> ostream &operator<<(ostream &os, vector<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A> ostream &operator<<(ostream &os, set<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A> ostream &operator<<(ostream &os, multiset<A> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A, typename B> ostream &operator<<(ostream &os, map<A,B> &v) {bool f=1;os << '['; for (auto &x : v){if(!f) os << ", "; f=0; os << x;} os << ']';}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &pr) {os << '(' << pr.first << ", " << pr.second << ')';}
string bin_string(int x) {
    const int d = 32;
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

int n;
vi ismax;
vector<vi> nodes;

int dfs(int u) {
    if (nodes[u].empty()) return 0;
    int res;
    if (ismax[u]) {
        res = INF;
        for (int v : nodes[u]) res = min(res, dfs(v));
    } else {
        res = 0;
        for (int v : nodes[u]) res += dfs(v);
        res += nodes[u].size()-1;
    }
    return res;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    ismax.resize(n);
    cin >> ismax;
    nodes.resize(n);
    REP(i, 1, n) {
        int p;
        cin >> p;
        --p;
        nodes[p].push_back(i);
    }
    int lvs = 0;
    REP(i, 0, n) if (nodes[i].empty()) ++lvs;
    println(lvs-dfs(0));
}