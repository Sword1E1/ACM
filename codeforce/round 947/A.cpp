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
	int n;cin >> n;
	vector<int>a(n + 5);
	for (int i = 1;i <= n;i++) cin >> a[i];
	int ok = 0;
	for (int i = 2;i <= n;i++) {
		if (a[i - 1] > a[i]) {
			if (!ok) {
				if (a[1] < a[n]) {
					cout << "NO" << '\n';
					return ;		
				}
				else ok = 1;
			}
			else {
				cout << "NO" << '\n';
				return ;
			}
		}
	}
	cout << "YES" << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin >> t;
	while (t--) solve();
	return 0;
}