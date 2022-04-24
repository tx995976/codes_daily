#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using ll = long long;
const int _mod = 998244353;
int N,M,K;
ll ans;
std::vector<std::vector<ll>> i_dp(51);

int main(){
    scanf(" %d %d %d",&N,&M,&K);
    for(auto &it : i_dp)
        it.resize(K+1,0ll);
    i_dp[0][0] = 1;
    for(int n = 0;n < N;n++)
        for(int k = 0;k < K;k++)
            for(int m = 1;m <= M;m++)
                if(m + k <= K)
                    (i_dp[n+1][k+m] += i_dp[n][k]) %= _mod;
    for(int i = 1;i <= K;i++)
        (ans += i_dp[N][i]) %= _mod;
    printf("%lld\n",ans);
    return 0;
}