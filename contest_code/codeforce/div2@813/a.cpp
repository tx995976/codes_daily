//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>

bool num[110];

int main(){
    int n,k,t;
    scanf("%d",&t);
    while(t--){
        memset(num,0,sizeof(num));
        scanf("%d %d",&n,&k);
        int d;
        for(int i = 1; i <= n; i++){
            scanf("%d",&d);
            num[d] = i > k ? 0 : 1;
        }
        int ans = 0;
        for(int i = 1; i <= k; i++)
            if(!num[i])
                ans += 1;
        printf("%d\n",ans);
    }

    return 0;
}