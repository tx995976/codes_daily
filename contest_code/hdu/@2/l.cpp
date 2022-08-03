//#动态规划/背包
//@离线
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;

const int lim = 365*4;

std::vector<ll> dp(lim+1,INT64_MAX-1ll);
ll coin[] = {7,31,365};

int main(){
    int t;
    scanf("%d",&t);
    dp[7] = dp[31] = dp[365] = 1ll;
    for(int i = 8;i <= lim;i++){
        for(ll it : coin){
            if(i > it)
                dp[i] = std::min(dp[i],dp[i-it]+1ll);
        }
    }
    while(t--){
        ll n;
        scanf("%lld",&n);
        if(n > lim){
            ll cnt = (n-lim)/365+1ll,   mod = n-cnt*365;
            printf("%lld\n",dp[mod] == INT64_MAX - 1ll ? -1ll : dp[mod]+cnt);
        }
        else
            printf("%lld\n",dp[n] == INT64_MAX - 1ll ? -1ll : dp[n]);
    }
    return 0;
}