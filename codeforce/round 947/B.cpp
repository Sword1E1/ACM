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
	vector <int> a(n + 5);
	set<int>s;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
    if ((int)s.size() == 1) {
        cout << "Yes" << '\n';
        return ;
    }
	int a1 = *(s.begin()),a2 = -1;
	sort(a.begin() + 1,a.begin() + 1 + n);
	for (int i = 1;i <= n;i++) {
		if (a2 == -1) {
            if (a[i] % a1 == 0) continue;
            else a2 = a[i];
        }
        else {
            if (a[i] % a1 == 0 || a[i] % a2 == 0) continue;
            cout << "No" << '\n';
            return ;
        }
	}
	cout << "Yes" << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin >> t;
	while (t--) solve();
	return 0;
}