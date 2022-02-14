#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<cstring>

const int max_n = 510;
int n,m,a,b;
int p_x[] = {1,-1,0,0},p_y[] ={0,0,1,-1};
char matix[max_n][max_n];
bool visit[max_n][max_n];
bool flag;

void dfs(int i,int j){
    visit[i][j] = 1;
    for(int c = 0;c < 4;c++){
        int a = i+p_x[c], b = j+p_y[c];
        if(a < 1 || a > n || b < 1 || b > m)
            continue;
        if(matix[a][b] == 'x'||visit[a][b])
            continue;
        visit[a][b] = 1;
        if(matix[a][b] == 't'){
            flag = 1;
            return;
        }
        dfs(a,b);
    }
}

int main(){
    int T;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d",&n,&m);
        memset(visit,0,sizeof(visit));
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++){
                scanf(" %c",&matix[i][j]);
                if(matix[i][j] == 's'){
                   a = i,b = j;
                }
            }
        flag = 0;
        dfs(a,b);
        printf("%s\n",flag ? "YES" : "NO");
    }
    return 0;
}