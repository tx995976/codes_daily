#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

const int max_n = 2*8+2;

int aff[max_n][max_n],ans;
bool flag[20];
int n;
std::vector<std::pair<int,int>> parten;

void dfs(int deep){
    if(deep == n+1){
        int temp = 0;
        for(auto it : parten)
            temp ^= aff[it.first][it.second];
        ans = std::max(ans,temp);
        return;
    }   
    int l;
    for(int i = 1;i < 2*n;i++){
        if(!flag[i]){
            l = i;
            break;
        }
    }
    flag[l] = 1;
    for(int i = 1;i <= 2*n;i++){
        if(!flag[i]){
            parten.push_back({l,i});
            flag[i] = 1;
            dfs(deep+1);
            parten.pop_back();
            flag[i] = 0;
        }
    }
    flag[l] = 0;
}

int main(){
    scanf(" %d",&n);
    for(int i = 1;i < 2*n;i++)
        for(int j = i+1;j <= 2*n;j++)
            scanf(" %d",&aff[i][j]);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}