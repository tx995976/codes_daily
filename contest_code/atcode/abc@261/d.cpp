//#动态规划
//@贪心
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 5e3+10;
using ll = long long;
ll p[2][max_n] = {}; 
ll exa_yen[max_n] = {},yen[max_n] = {};

int main(){
    int n,m,c;
    scanf(" %d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&yen[i]);

    for(int i=1;i<=m;i++){
        scanf(" %d",&c);
        scanf(" %lld",&exa_yen[c]);
    }
    int g = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= i;j++)
            p[g^1][0] = std::max(p[g^1][0],p[g][j]);
        for(int j = 1;j <= i;j++){
            p[g^1][j] = p[g][j-1] + yen[i] + exa_yen[j];
        }
        g ^= 1;
    }
    ll ans = 0ll;
    for(int i = 0;i <= n;i++){
        ans = std::max(p[g][i],ans);
    }
    printf("%lld\n",ans);
    return 0;
}