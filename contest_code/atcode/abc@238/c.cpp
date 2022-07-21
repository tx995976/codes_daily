#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = long long;
const int mod_ = 998244353;
ll ans = 0ll,n;

ll add(ll x){
    x %= mod_;
    x = x*(x+1)/2;
    x %= mod_;
    return x;
}

int main(){
    scanf(" %lld",&n);
    ll bit_ = 10;
    ll l,r;
    for(int i = 1;i <= 18;i++){
        l = bit_ / 10;
        r = std::min(bit_-1,n);
        if(l <= r){
            ans += add(r-l+1);
            ans %= mod_;
        }
        bit_ *= 10;
    }
    printf("%lld\n",ans);
    return 0;
}