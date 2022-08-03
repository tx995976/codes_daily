//#数学/逆元
//
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

int n,m;
const int _mod = 1e9+7;
int g = (_mod+1)/2;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        printf("%lld\n",1ll*(n-m)*g%+_mod);
    }

    return 0;
}