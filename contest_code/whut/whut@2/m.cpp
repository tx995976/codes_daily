#include<iostream>
#include<algorithm>
#include<cstdio>

const int max_n = 1e4+10;
int n,m,ans,qs[max_n]={0},plus[max_n] = {0},qs_p[max_n] = {0};

int main(){
    scanf("%d %d",&n,&m);
    for(int i =1;i <= n;i++){
        scanf("%d",&qs[i]);
        qs_p[i] = qs_p[i-1] + qs[i];
        plus[i] = plus[i-1] + qs[i]*i;
    }
    if(plus[n] < m){
        printf("%d\n",-1);
        return 0;
    }

    auto a = std::upper_bound(plus+1,plus+n+1,m);
    int i = a - plus;
    ans = qs_p[i];

    int temp = plus[i] - m;
    while(temp != 0){
        ans -= temp / i;
        temp %= i--;
    }
    printf("%d\n",ans);
    
    return 0;
}