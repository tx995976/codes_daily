#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = long long;
int t;
ll a,s,s_a;

int main(){
    scanf(" %d",&t);
    while(t--){
        bool flag = 0;
        scanf(" %lld %lld",&a,&s);
        if(a*2 <= s){
            s_a = s - a*2;
            if((s_a & a) == 0)
                flag = 1;
        }
        printf("%s\n",flag ? "Yes" : "No");
    }

    return 0;
}