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
int a[maxn],dfn[maxn],cnt,dep[maxn],fa[maxn][35],to[maxn];
set<int>s;

void dfs(int u,int f) {
    dfn[u] = ++cnt;
    to[cnt] = u;
    for (auto i : t[u]) {
        if (i == f) continue;
        dep[i] = dep[u] + 1;
        fa[i][0] = u;
        for (int j = 1;j <= 30;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
        dfs(i,u);
    }
}

int lca(int u,int v) {
    if (dep[u] < dep[v]) swap(u,v);
    for (int j = 30;j >= 0;j--) {
        if (dep[fa[u][j]] >= dep[v]) u = fa[u][j];
    }
    if (u == v) return u;
    for (int j = 30;j >= 0;j--) {
        if (fa[u][j] != fa[v][j]) {
            u = fa[u][j];
            v = fa[v][j];
        }
    }
    return fa[u][0];
}

void solve() {
    s.clear();
    int n,q;cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        to[i] = 0;
        t[i].clear();
        dfn[i] = dep[i] = 0;
        for (int j = 0;j <= 30;j++) fa[i][j] = 0;
    }
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i < n;i++) {
        int u,v;cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1,0);
    for (int i = 1;i <= n;i++) {
        if (a[i] == 1) s.insert(dfn[i]);
    }
    while (q--) {
        int x;cin >> x;
        a[x] ^= 1;
        if (a[x] == 1) {
            s.insert(dfn[x]);
            if ((int)s.size() == 0) {
                cout << "No" << '\n';
                continue;
            }
            if ((int)s.size() == 1) {
                cout << "Yes" << '\n';
                continue;
            }
            int now = (int)s.size();
            //dbg(now);
            int mi = *(s.begin()),mx = *(prev(s.end()));
            int allf = lca(to[mi],to[mx]);
            //dbg(to[mx],allf);
            int dis = dep[to[mx]] - dep[allf] - 1;
            now -= dep[to[mx]] - dep[allf];
            int v = to[mx];
            for (int i = 30;i >= 0;i--) {
                if (dis >= (1ll << i)) {
                    dis -= (1ll << i);
                    v = fa[v][i];
                }
            }
            auto it = lower_bound(s.begin(),s.end(),dfn[v]);
            int u = to[*(prev(it))];
            //dbg(u,now);
            now -= dep[u] - dep[allf] + 1;
            //dbg(now);
            if (now == 0) {
                cout << "Yes" << '\n';
            }
            else cout << "No" << '\n';
        }
        else {
            s.erase(dfn[x]);
            if ((int)s.size() == 0) {
                cout << "No" << '\n';
                continue;
            }
            if ((int)s.size() == 1) {
                cout << "Yes" << '\n';
                continue;
            }
            int now = (int)s.size();
            int mi = *(s.begin()),mx = *(prev(s.end()));
            int allf = lca(to[mi],to[mx]);
            int dis = dep[to[mx]] - dep[allf] - 1;
            now -= dep[to[mx]] - dep[allf];
            int v = to[mx];
            for (int i = 30;i >= 0;i--) {
                if (dis >= (1ll << i)) {
                    dis -= (1ll << i);
                    v = fa[v][i];
                }
            }
            auto it = lower_bound(s.begin(),s.end(),dfn[v]);
            int u = to[*(prev(it))];
            now -= dep[u] - dep[allf] + 1;
            if (now == 0) {
                cout << "Yes" << '\n';
            }
            else cout << "No" << '\n';
        }
    }
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin >> t;
	while (t--) solve();
	return 0;
}