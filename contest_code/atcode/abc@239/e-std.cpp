#include<bits/stdc++.h>
using namespace std;
const int MX=1e5+5;
int a[MX];
int n, m, u, v, k;
vector<int>g[MX];
vector<int>f[MX];

void dfs(int u, int fa) {
	f[u].push_back(a[u]);
	for (int v : g[u]) {
		if (v == fa)continue;
		dfs(v, u);
		for (int x : f[v])f[u].push_back(x);
	}
	sort(f[u].begin(), f[u].end(), greater<int>());
	while (f[u].size() > 20)f[u].pop_back();
}
 
int main(){
    cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	while (m--) {
		cin >> u >> k;
		cout << f[u][k - 1] << endl;
	}
	return 0;
}