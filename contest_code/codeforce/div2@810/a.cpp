#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1; i <= n; i++){
            if(i == 1)
                printf("%d ",n);
            else
                printf("%d ",i-1);
        }
        printf("\n");
    }
    return 0;
}