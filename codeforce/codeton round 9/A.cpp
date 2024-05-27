#include <bits/stdc++.h>
using namespace std;
#define int long long

#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)

void err() {
	std::cout << std::endl;
}

template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

void solve() {
	
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin >> t;
	while (t--) solve();
	return 0;
}