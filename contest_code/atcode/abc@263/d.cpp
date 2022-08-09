//#动态规划
//@
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
const int max_n = 2e5+10;
ll arr_sum [max_n];
ll l_v[max_n],r_v[max_n];
ll min_l[max_n],min_r[max_n];

int main(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&arr_sum[i]);
        arr_sum[i] += arr_sum[i-1];
    }
    
    for(int i = 1; i <= n; i++){
        ll f = l_v[i-1];
        if(f*l + arr_sum[i]-arr_sum[f] > 1ll*i*l ){
            l_v[i] = i;
            min_l[i] = 1ll*i*l;
        }
        else{
            l_v[i] = f;
            min_l[i] = f*l + arr_sum[i]-arr_sum[f];
        }
    }
    for(int i = n; i >= 1;i--){
        ll f = r_v[i+1];
        if(f*r + arr_sum[n-f]-arr_sum[i-1] > 1ll*(n-i+1)*r){
            r_v[i] = n-i;
            min_r[i] = 1ll*(n-i+1)*r;
        }
        else{
            r_v[i] = f;
            min_r[i] = f*r + arr_sum[n-f]-arr_sum[i-1];
        }
    }

    ll ans = INT64_MAX;
    for(int i = 0; i <= n; i++)
        ans = std::min(ans,min_l[i]+min_r[i+1]);
    printf("%lld\n",ans);
    return 0;
}