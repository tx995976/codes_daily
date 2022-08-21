//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using ll = long long;

int get_di(ll d){
    int di = 1;
    while((d /= 10ll))
        di++;
    return di;
}

ll sprit_num(ll d,int di,int div){
    if(di % div != 0)
        return 0ll;
    ll _mod = std::pow(10ll,di/div);
    std::vector<ll> cp;
    ll n = d;
    while(n){
        cp.push_back(n%_mod);
        n /= _mod;
    }
    ll res = 0ll,top = cp.back();
    while(get_di(top) >= di/div){
        for(int i = 0;i < div;i++){
            res *= _mod;
            res += top;
        }
        if(res <= d)
            break;
        else{
            top -= 1ll;
            res = 0ll;
        }
    }
    return res;
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll n;
        scanf("%lld", &n);
        int di = get_di(n);
        ll ans = 0ll;
        for(int i = 2;i <= di;i++)
            ans = std::max(ans,sprit_num(n,di,i));

        if(ans == 0){
            di -= 1ll;
            for(int i = 0;i < di;i++){
                ans *= 10ll;
                ans += 9ll;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}