#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

int encodata,P,Q;
using ll = long long;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&P,&Q,&encodata);
        ll KM = 1ll * P * Q - 1, raw = -1, M;
        for(ll i = 2; i * i <= KM;i++){
            if(KM % i)
                continue;
            while(KM % i == 0)
                KM /= i;
            M = i;
        }
        if(KM > 1)
            M = KM;
        if(P < M && Q < M)
            raw = 1ll * encodata * Q % M;
        if(raw != -1)
            printf("%lld\n",raw);
        else
            printf("shuanQ\n");
    }

    return 0;
}