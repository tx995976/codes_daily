#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

const int max_n = 10;
int table[max_n][max_n];
int space = 0;
std::vector<std::pair<int,int>> pos;//<x,y>  
bool f_x[max_n][max_n],f_y[max_n][max_n],f_b[max_n][max_n];


int group [10][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,2,2,2,3,3,3},
    {0,1,1,1,2,2,2,3,3,3},
    {0,1,1,1,2,2,2,3,3,3},
    {0,4,4,4,5,5,5,6,6,6},
    {0,4,4,4,5,5,5,6,6,6},
    {0,4,4,4,5,5,5,6,6,6},
    {0,7,7,7,8,8,8,9,9,9},
    {0,7,7,7,8,8,8,9,9,9},
    {0,7,7,7,8,8,8,9,9,9},};

void print_tab(){
    for(int i = 1;i <= 9;i++)
        for(int j = 1;j <= 9;j++)
            printf("%d%c",table[i][j],j == 9 ? '\n' : ' ');
}

void dfs(int round){
    if(round > space){
        print_tab();
        return;
    }
    int tx = pos[round-1].first;
    int ty = pos[round-1].second;
    for(int i = 1;i <= 9;i++){
        if(!f_x[tx][i] && !f_y[ty][i] && !f_b[group[tx][ty]][i]){
            f_x[tx][i]  = f_b[group[tx][ty]][i] = f_y[ty][i] = 1;
            table[tx][ty] = i;
            dfs(round+1);
            f_x[tx][i]  = f_b[group[tx][ty]][i] = f_y[ty][i] = 0;
        }
    }
}

int main(){
    for(int i = 1;i <= 9;i++)
        for(int j = 1;j <= 9;j++){
            scanf(" %d",&table[i][j]);
            if(table[i][j] == 0){
                pos.push_back({i,j});
                space++;
            }
            else{
                f_x[i][table[i][j]] = 1;
                f_y[j][table[i][j]] = 1;
                f_b[group[i][j]][table[i][j]] = 1;
            }
        }
    dfs(1);
    return 0;
}


