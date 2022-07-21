#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<queue>

using ll = long long;
const int max_n = 2e5+10;
ll n,k,x;
ll price[max_n];

//std::vector<int> mod_;

int main(){
    scanf(" %lld %lld %lld",&n,&k,&x);
    for(int i = 1;i <= n;i++)
        scanf(" %d",&price[i]);
    //std::sort(price+1,price+n+1,std::greater<int>());
    ll n_k = 0ll;
    ll need = 0ll;
    for(int i = 1;i <= n;i++){ 
        n_k += price[i] / x;
        price[i] %= x;
    }
    ll judge = n_k - k;
    n_k = std::min(n_k,k);
    k -= n_k;
    if(judge > 0){
        need += judge * x;
    }
    std::sort(price+1,price+n+1,std::greater<int>());
    for(int i = 1;i <= n;i++){
        if(k == 0){
            need += price[i];
            continue;
        }
        k--;
    }
    printf("%lld\n",need);
    return 0;
}