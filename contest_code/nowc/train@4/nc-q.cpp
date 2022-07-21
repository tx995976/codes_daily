#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = long long;
const int max_n = 2e5+10;

ll com_card[max_n],my_card[max_n];
ll ans = 0;

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++)
        scanf(" %lld",&com_card[i]);
    for(int i = 1;i <= n;i++)
        scanf(" %lld",&my_card[i]);
    std::sort(com_card+1,com_card+1+n);
    std::sort(my_card+1,my_card+1+n,std::greater<ll>());
    int i = 1,flag = 1;
    while(i <= n && flag){
        if(com_card[i] <= my_card[i])
            ans += my_card[i] - com_card[i];
        else
            flag = 0;
        i++;
    }
    printf("%lld\n",ans);
    return 0;
}