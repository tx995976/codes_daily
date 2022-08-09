#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

int num[20];
int n,m;

void dfs(int c,int i){
    if(n == c){
        for(int j = 1;j <= n;j++)
            printf("%d ",num[j]);
        printf("\n");
        return;
    }
    if(i > m)
        return;
    num[c+1] = i;
    dfs(c+1,i+1);
    num[c+1] = 0;

    dfs(c,i+1);
}

int main(){
    scanf("%d %d",&n,&m);
    dfs(0,1);
    return 0;
}