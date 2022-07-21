#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<queue>

using ll = long long;
const int mod_ = 998244353;
ll x,ans = 1ll,temp;

std::queue<ll> nums;

long long fast_pow(long long a,long long b){
    long long res = 1ll;
    for(;b;b >>= 1){
        if(b & 1)
            (res *= a);
        (a *= a);
    }
    return res;
}

int main(){
    scanf(" %lld",&x);
    int cnt_2 = 0,cnt_3 = 0;
    int cnt2,cnt3;
    int round = 0;
    while(x < 5ll){
        cnt2 = 0; cnt3 = 0;
        if(x & 1){
            cnt2 += cnt_3;
            if(((x + 1ll)>>1) & 1){
                cnt3 += cnt_2;
                
            }
            else
                cnt2 += cnt_2 << 1;
            
        }
        else{

        }
    }
    printf("%lld\n",ans);
    return 0;
}
