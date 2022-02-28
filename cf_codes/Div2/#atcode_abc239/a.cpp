#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = long long;
const ll Ho = 12800000;
long double ans;
ll i;

int main(){
    scanf(" %lld",&i);
    ans = std::sqrt(i*(i+Ho));
    printf("%.9Lf\n",ans);
    return 0;
}