// <?
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
const int max_n = 4e3+10;
int N,_mod;
ll dp[max_n][max_n];
ll sum[max_n][max_n];
ll oct_dit[] = {1,10,100,1000,10000};


long long fast_pow(long long a,long long b){
    long long res = 1ll;
    for(;b;b >>= 1){
        if(b & 1)
            (res *= a) %= _mod;
        (a *= a) %= _mod;
    }
    return res;
}

int main(){
    scanf(" %d %d",&N,&_mod);

    dp[0][0] = fast_pow(25,_mod-2)* 26ll % _mod;
    for(int i = 1;i <= N;i++)
        sum[0][i] = dp[0][0];

    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++){
            for(int k = 1;k <= 4;k++){
                if(i-k-1 < 0) 
                    continue;
                ll x = std::max(j-oct_dit[k-1]+1,0ll),y = std::max(j-oct_dit[k]+1,0ll);
                (dp[i][j] += (sum[i-k-1][x]-sum[i-k-1][y]+_mod)*25) %= _mod;
            }
            (sum[i][j+1] = sum[i][j]+dp[i][j]) %= _mod;
        }

    ll ans = 0ll;
    for(int i = 1;i < N;i++)
        (ans += dp[i][N]) %= _mod;
    printf("%lld\n",ans);
    return 0;
}