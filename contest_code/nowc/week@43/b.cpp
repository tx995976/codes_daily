#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using ll = long long;
ll a,b,tar,temp;
int T,cnt;

int main(){
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%lld %lld %lld",&a,&b,&tar);
        //
        if(a == tar || b == tar){
            printf("0\n");
            continue;
        }
        //
        if(tar&1){
            printf("-1\n");
            continue;
        }
        temp = (a + b)<<1;
        cnt = 1;
        while(temp < tar){
            cnt++;
            temp <<= 1;
        }
        
        printf("%d\n",cnt);
    }

    return 0;
}