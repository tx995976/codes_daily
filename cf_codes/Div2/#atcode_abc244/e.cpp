#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>
#include<array>

using ll = long long;
const int max_n = 2e3+10;
const int mod_ = 998244353;

std::vector<std::pair<int,int>>edge;
int N,M,K,S,T,X;
int d1,d2;
//ll ans = 0;

int main(){
    scanf(" %d %d %d %d %d %d",&N,&M,&K,&S,&T,&X);
    for(int i = 1;i <= M;i++){
        scanf(" %d %d",&d1,&d2);
            edge.push_back({d1,d2});
    }
    //
    std::vector dp(K+1,std::vector(N+1,std::array<ll,2>{0,0}));
    //
    dp[0][S][0] = 1ll;
    for(int i = 0;i < K;i++)
        for(auto [f,t] : edge)
            for(int x : {0,1}){
                (dp[i+1][t][x ^ (t == X)] += dp[i][f][x]) %= mod_;
                (dp[i+1][f][x ^ (f == X)] += dp[i][t][x]) %= mod_;
            }
    printf("%lld\n",dp[K][T][0]);
    return 0;
}