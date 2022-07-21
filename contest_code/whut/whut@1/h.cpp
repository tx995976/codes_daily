#include<iostream>
#include<algorithm>
#include<cstdio>

using ll = long long;

const long long _mod = 1e9+7;
ll l,r,ans = 1ll;
int t;

struct bit_node{
    long long bit,cnt;
    bit_node(long long a,long long b){bit = a;cnt = b;}
    bit_node(){}
};

bit_node bit[64];
bool cmp(const bit_node &l , const bit_node &r){
    return l.cnt > r.cnt;
}

long long fast_pow(long long a,long long b){
    long long res = 1ll;
    for(;b;b >>= 1){
        if(b & 1)
            (res *= a) %= _mod;
        (a *= a) %= _mod;
    }
    return res;
}

ll bit_cnt(ll bit, ll in){
    if(!in) return 0;
    ll len = (1ll << bit) , a_p = (1ll << (bit+1));
    // a_p << 1 == a_p - len ???
    ll cnt = in / a_p * len;
    ll mod_in = in % a_p;
    if(mod_in >= len)
        cnt += mod_in - len + 1;
    return cnt;
}

long long solve(){

    for(int i = 0;i < 60;i++){
        bit[i].bit = i; bit[i].cnt = 0;
        bit[i].cnt = bit_cnt(i,r) - bit_cnt(i,l-1);
        //printf("%lld\n",bit[i].cnt);
    }

    ll k_max = 0;
    for(int i = 1;i < 60;i++)
       k_max = std::max(k_max,bit[i].cnt);
    ll t = (r - l + 1ll) - k_max;
    bit[0].cnt -= t;
    std::sort(bit,bit+60,cmp);

    ans = 1ll;
    ll n = 0;
    for(int i = 0; i < 60;i++){
        (n += (1ll << bit[i].bit)) %= _mod;
        if(bit[i].cnt != bit[i+1].cnt){
            ans = ans * fast_pow(n,bit[i].cnt - bit[i+1].cnt) % _mod;
           // printf("%lld %lld\n",n,bit[i].cnt - bit[i+1].cnt);
        }
    }
    return ans;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",solve());
    }
   
    return 0;
}