#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = int64_t;
std::string in;
int Q;
ll t,k;

char per(char x,ll t_){
    return ('A'+(x-'A'+t_)%3);
}

char solve(ll ti,ll ki){
    if(ti == 0)
        return in[ki];
    if(ki == 0)
        return per(in[0],ti);
    return per(solve(ti-1,ki/2),ki%2+1);
}

int main(){
    std::cin>>in;
    scanf(" %d",&Q);
    while(Q--){
        scanf(" %lld %lld",&t,&k);
        printf("%c\n",solve(t,k-1));
    }
    return 0;
}