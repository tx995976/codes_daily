//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using ll = long long;

ll reser(ll a){
    int b[13],cnt = 0;
    ll res = 0ll,bit = 1ll;
    while(a){
        b[++cnt] = a%10ll;
        a /= 10ll;
    };
    for(int i = cnt;i > 0;i--){
        res += bit*b[i];
        bit *= 10ll;
    }
    return res;
}

int main(){
    ll n,k,cnt = 0ll;
    scanf("%lld %lld",&n,&k);
    if(n < k)
        cnt = 0ll;
    else if(k % 10ll == 0)
        cnt = 0ll;
    else if(k > reser(k))
        cnt = 0ll;
    else{
        ll res_k = reser(k);
        ll cnt_k= 0ll,cnt_sk = 0ll;
        //printf("%lld %lld\n",res_k,k);
        if(res_k != k)
            while(res_k <= n){
                cnt_sk++;
                res_k *= 10ll;
            }
        while(k <= n){
            cnt_k++;
            k *= 10ll;
        }
        cnt = cnt_k + cnt_sk;
    }
    printf("%lld\n",cnt);
    return 0;
}