#include <bits/stdc++.h>
using namespace std;

// nice things
typedef long long lglg;
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#define help(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); _help(_it, args); }
void _help(istream_iterator<string> it) {}
template<typename T, typename... Args>
void _help(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " is " << a << "\n";
	_help(++it, args...);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		lglg x,y; cin >> x >> y;
		cout << (x-y == 1 ? "NO" : "YES") << '\n';
	}
}