#include<cstdio>
#include<algorithm>
#include<cstring>

using ll = long long;

const int max_n = (1<<17)+10;

int c[max_n][17];
ll dp[max_n][17];
int n;

ll dfs(int p,int r){
    if(p >= (1<<n))
        return c[p^(1<<n)][r];  
    if(dp[p][r] != 0)
        return dp[p][r];
    ll res = std::max(dfs(p<<1,r+1)+dfs(p<<1|1,0),dfs(p<<1,0)+dfs(p<<1|1,r+1));
    return dp[p][r] = res;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < (1<<n);i++)
        for(int j = 1;j <= n;j++){
            scanf("%d",&c[i][j]);
        }
    printf("%lld\n",dfs(1,0));
    return 0;
}