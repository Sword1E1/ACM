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
    if (n == 2) {
        cout << min(a[1],a[2]) << '\n';
        return ;
    }
    int res = 0;
    for (int i = 1;i <= n;i++) {
        if (i + 2 > n) break;
        multiset<int>s;
        for (int j = i;j <= i + 2;j++) s.insert(a[j]);
        int ans = *(next(s.begin()));
        res = max(res,ans);
    }
    cout << res << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin >> t;
	while (t--) solve();
	return 0;
}