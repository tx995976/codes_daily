#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

using ll = long long;
const int max_n = 3e2+10;
int n,m,ai,bi,ans = 0;
ll ci;

struct edge{int a,b;ll c;};

std::vector<ll> C[max_n];
std::vector<edge> ed;

int main(){
    scanf(" %d %d",&n,&m);
    for(int i = 1;i <= n;i++)
        C[i].resize(n+1,1e18);
    ed.resize(m+1);
    for(int i = 1;i <= m;i++){
        scanf(" %d %d %lld",&ai,&bi,&ci);
        ed[i] = {ai,bi,ci};
        C[ai][bi] = ci;
        C[bi][ai] = ci;
    }
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                C[i][j] = std::min(C[i][j],C[i][k]+C[k][j]);

    for(int i = 1;i <= m;i++){
        int plus = 0;
        for(int j = 1;j <= n;j++)
            if(C[ed[i].a][j] + C[j][ed[i].b] <= ed[i].c)
                plus = 1;
        ans += plus;
    }
    printf("%d\n",ans);
    return 0;
}