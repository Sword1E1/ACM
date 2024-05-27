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

const int maxn = 2e5 + 5;
vector<int>t[maxn];
int dep[maxn],fa[maxn][35];
int ans,mx,p;

void dfs(int u,int f) {
    int ok = 1;
    for (auto i : t[u]) {
        if (i == f) continue;
        ok = 0;
        dep[i] = dep[u] + 1;
        fa[i][0] = u;
        for (int j = 1;j <= 30;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
        dfs(i,u);
    }
    if (ok) {
        if (mx < dep[u]) {
            mx = dep[u];
            p = u;
        }
    }
}

void solve() {
	int n;cin >> n;
    for (int i = 1;i <= n;i++) {
        t[i].clear();
        dep[i] = 0;
        for (int j = 0;j <= 30;j++) fa[i][j] = 0;
    }
    int n1,n2;cin >> n1 >> n2;
    for (int i = 1;i < n;i++) {
        int u,v;cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs(n2,0);
    if (dep[n1] % 2 == 0) {
        ans = 0;
        int dis = dep[n1] / 2;
        ans += dis;
        for (int i = 30;i >= 0;i--) {
            if (dis >= (1ll << i)) {
                dis -= (1ll << i);
                n1 = fa[n1][i];
            }
        }
        for (int i = 1;i <= n;i++) {
            dep[i] = 0;
            for (int j = 0;j <= 30;j++) fa[i][j] = 0;
        }
        mx = 0;
        dfs(n1,0);
        ans += (n - 1) * 2;
        while (fa[p][0]) {
            ans--;
            p = fa[p][0];
        }
        cout << ans << '\n';
    }
    else {
        ans = 0;
        int dis = dep[n1] / 2;
        ans += dis;
        for (int i = 30;i >= 0;i--) {
            if (dis >= (1ll << i)) {
                dis -= (1ll << i);
                n1 = fa[n1][i];
            }
        }
        for (int i = 1;i <= n;i++) {
            dep[i] = 0;
            for (int j = 0;j <= 30;j++) fa[i][j] = 0;
        }
        mx = 0;
        //dbg(fa[1][0],fa[2][0]);
        dfs(n1,0);
        ans += (n - 1) * 2;
        //dbg(p);
        //dbg(fa[1][0],fa[2][0]);
        while (fa[p][0]) {
            ans--;
            p = fa[p][0];
        }
        ans++;
        cout << ans << '\n';
    }
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin >> t;
	while (t--) solve();
	return 0;
}