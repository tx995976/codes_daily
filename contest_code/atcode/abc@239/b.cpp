#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = long long;
ll x;

int main(){
    scanf(" %lld",&x);
    if(x < 0 && ((x % 10ll) != 0ll))
        x = (x/10ll)-1ll;
    else
        x = (x/10ll);
    printf("%lld\n",x);
    return 0;
}