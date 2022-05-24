#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<queue>

using ll = long long;
const int max_n = 1e5+10;
int n,m;
std::priority_queue<ll,std::vector<ll>,std::greater<ll>> att;
long long a[max_n],x;

int main(){
    scanf(" %d %d %lld",&n,&m,&x);
    for(int i = 1;i <= n;i++){
        scanf(" %lld",&a[i]);
        a[i] = (a[i] + x - 1ll) / x;            
    }
    for(int i = 1;i <= m;i++)
        att.push(a[i]);
    for(int i = m+1;i <= n;i++){
        ll top = att.top();
        att.pop();
        att.push(a[i] + top);
    }
    long long ans;
    while(!att.empty()){
        ans = att.top();
        att.pop();
    }
    printf("%lld\n",ans);
    return 0;
}