#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 310, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
vector<int> level[N];
int c[M], cnt[N];
int ans = N;

void add(int u, int v)
{
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

int dfs_level(int u, int d, int fa)
{
    cnt[u] = 1;
    for (int i=h[u]; ~i; i=ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        cnt[u] += dfs_level(j, d + 1, u);
        level[d].push_back(i);
    }
    return cnt[u];
}

void dfs_draw(int j, int color)
{
    c[j] = color;
    for (int i=h[e[j]]; ~i; i=ne[i])
        if (i != (j ^ 1))   // i不是j的反向边
            dfs_draw(i, color);
}

void dfs(int u, int s)
{
    ans = min(ans, s);
    for (int i=0; i<level[u].size(); i++ )
    {
        int j = level[u][i];
        if (!c[j])
        {
            dfs_draw(j, 1);
            dfs(u + 1, s - cnt[e[j]]);
            dfs_draw(j, 0);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i=1; i<=m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(v, u), add(u, v);
    }
    dfs_level(1, 0, -1);
    dfs(0, n);
    printf("%d\n", ans);
    return 0;
}
