#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
ll N,a,b,ans;


int main(){
    scanf(" %lld %lld %lld",&N,&a,&b);
    ans = 0ll;
    if(a <= b){
        if(N > (a-1ll))
            ans = (N-(a-1ll));
    }
    else{
        ll cnt = N/a-1ll,mod = N%a;
        if(cnt >= 0)
            ans += cnt*b + (mod >= b-1ll ? b : mod+1ll);
    }
    printf("%lld\n",ans);
    return 0;
}