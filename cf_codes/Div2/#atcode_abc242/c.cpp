#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = int64_t;
const ll mod = 998244353,max_n = 1e6+10;

int N;
ll DP[max_n][10];
ll ans;

void search(){
    for(int i = 2;i <= N;i++){
        DP[i][1] = (DP[i-1][1] + DP[i-1][2]) % mod;
        DP[i][2] = (((DP[i-1][1] + DP[i-1][2]) % mod)+ DP[i-1][3]) % mod;
        DP[i][3] = (((DP[i-1][2] + DP[i-1][3]) % mod)+ DP[i-1][4]) % mod;
        DP[i][4] = (((DP[i-1][3] + DP[i-1][4]) % mod)+ DP[i-1][5]) % mod;
        DP[i][5] = (((DP[i-1][4] + DP[i-1][5]) % mod)+ DP[i-1][6]) % mod;
        DP[i][6] = (((DP[i-1][5] + DP[i-1][6]) % mod)+ DP[i-1][7]) % mod;
        DP[i][7] = (((DP[i-1][6] + DP[i-1][7]) % mod)+ DP[i-1][8]) % mod;
        DP[i][8] = (((DP[i-1][7] + DP[i-1][8]) % mod)+ DP[i-1][9]) % mod;
        DP[i][9] = (DP[i-1][8] + DP[i-1][9]) % mod;
    }
}

int main(){
    scanf(" %d",&N);
    for(int i = 1;i <= 9;i++)
        DP[1][i] = 1;
    search();
    for(int i = 1;i <= 9;i++)
        ans = (ans + DP[N][i]) % mod ;
    printf("%lld\n",ans); 
    return 0;
}