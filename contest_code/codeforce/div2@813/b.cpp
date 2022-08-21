//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 1e5+10;

int ans[max_n];

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = n-1;i > 0;i -= 2)
            ans[i] = i+1,ans[i+1] = i;
        
        if(n & 1)
            ans[1] = 1;
        for(int i = 1;i <= n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }

    return 0;
}