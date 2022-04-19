#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

using ll = long long;
const ll lim = 7e18;
const int lim_si = 1e6;
ll N,tmp,ans=lim;
int a,b;

ll get_ans(ll a,ll b){
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main(){
    scanf(" %lld",&N);
    int a = 0,b = lim_si;
    while(a <= b){
        while((tmp=get_ans(a,b)) >= N){
            ans = std::min(ans,tmp);
            b--;
        }
        a++;
    }
    printf("%lld\n",ans);
    return 0;
}