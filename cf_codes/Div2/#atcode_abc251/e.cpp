#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
const int max_n = 3e5+10;
int ai,n;
int c[max_n];
std::vector<std::vector<ll>> dp_1,dp_2;

int main(){
    scanf(" %d", &n);
    for(int i=1;i <= n;i++){
        scanf(" %d", &c[i]);
    }
    dp_1.resize(n+1,std::vector<ll>(2,INT32_MAX));
    dp_2.resize(n+1,std::vector<ll>(2,INT32_MAX));

    dp_1[1][0] = 0;
    dp_2[1][1] = c[1];

    for(int i = 2;i <= n;i++){
        dp_1[i][0] = dp_1[i-1][1];
        dp_1[i][1] = std::min(dp_1[i-1][0],dp_1[i-1][1]) + c[i];
        dp_2[i][0] = dp_2[i-1][1];
        dp_2[i][1] = std::min(dp_2[i-1][0],dp_2[i-1][1]) + c[i];
    }

    ll ans = std::min({dp_1[n][1],dp_2[n][1],dp_2[n-1][1]});
    printf("%lld\n",ans);
    return 0;
}