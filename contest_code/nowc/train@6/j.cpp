#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

using ll = long long;
std::vector<ll> luc_num;
ll l,r;
ll ans = 0;

void table(ll x){
    if(x > 1e10)
        return;
    luc_num.push_back(x);
    table(x*10+4);
    table(x*10+7);
}

int main(){
    scanf(" %lld %lld",&l,&r);
    table(0);
    std::sort(luc_num.begin(),luc_num.end());
    int pos = 1;
    while(l <= r){
        while(l > luc_num[pos])
            pos++;
        if(r < luc_num[pos]){
            ans += ((r-l+1ll)*luc_num[pos]);
            l = r+1ll;
        }
        else{
            ans += ((luc_num[pos]-l+1ll)*luc_num[pos]);
            l = luc_num[pos]+1ll;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
