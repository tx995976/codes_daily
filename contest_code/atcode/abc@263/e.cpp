//#动态规划/概率DP
//@数学
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;

const int _mod = 998244353;
const int max_n = 2e5+10;

ll arr[max_n],dp[max_n],sum[max_n];

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
    int n;
    scanf("%d",&n);
    for(int i = 1; i < n; i++)
        scanf("%lld",&arr[i]);
    for(int i = n-1;i >= 1;i--){
        dp[i] = ((sum[i+1] - sum[i+arr[i]+1]+ 1ll + _mod)%_mod*fast_pow(arr[i],_mod-2) % _mod + 1ll)%_mod;
        sum[i] = (sum[i+1] + dp[i])%_mod;
    }
    printf("%lld\n",dp[1]);
    return 0;
}