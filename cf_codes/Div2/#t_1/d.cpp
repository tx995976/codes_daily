#include<iostream>
#include<algorithm>
#include<cstdio>

using ll = long long;
ll k,x,all,ans;
int t;

ll get_spam(ll in){
    ll t = (k*2-1ll) - in;
    return in > k ? all-(t*(t+1ll)/2) : in*(in+1ll)/2;
}

ll k_upper_bound(ll first,ll last,ll value){
    ll l = first,count = last,mid;
    while(count > 0){
        l = first;
        mid = count / 2;
        l += mid;
        if(get_spam(l) < value){
            first = ++l;
            count -= mid + 1;
        }
        else
            count = mid;
    }
    return first;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&k,&x);
        all = k*k;
        ans = k_upper_bound(1ll,k*2-1ll,x);
        if(ans == k*2)
            ans = k*2-1ll;
        printf("%lld\n",ans);
    }

    return 0;
}