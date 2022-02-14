#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

using ll = long long;
std::vector<ll> luc_num;
int l,r;
ll ans = 0;

void table(int x){
    if(x > 1e9)
        return;
    luc_num.push_back(x);
    table(x*10+4);
    table(x*10+7);
}

int main(){
    scanf(" %d %d",&l,&r);
    table(0);
    std::sort(luc_num.begin(),luc_num.end());
    int pos = 1;
    while(l < r){
        while(l > luc_num[pos])
            pos++;
        if(r < luc_num[pos]){
            ans += (ll)(r-l+1) * luc_num[pos];
            l = r+1;
        }
        else{
            ans += (ll)(luc_num[pos]-l+1) * luc_num[pos];
            l = luc_num[pos]+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
