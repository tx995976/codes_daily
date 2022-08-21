#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using ll = long long;
ll a[3];

int main(){
    scanf(" %lld %lld %lld",&a[0],&a[1],&a[2]);
    std::sort(a,a+3);
    bool flag = 0;
    if(a[2]*2 - a[1] - a[0] <= a[2])
        flag = 1;
    printf("%lld\n",flag ? a[2] : -1ll);
    return 0;
}