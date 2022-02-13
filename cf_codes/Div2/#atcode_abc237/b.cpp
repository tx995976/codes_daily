#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

const int max_n = 1e5;
std::vector<int> matix[max_n];
int H,W;

int main(){
    int temp;
    scanf(" %d %d",&H,&W);
    for(int i = 0;i < H;i++)
        for(int j = 1;j <= W;j++){
            scanf(" %d",&temp);
            matix[i].push_back(temp);
        }
    for(int i = 0;i < W;i++)
        for(int j = 0;j < H;j++)
            printf("%d%c",matix[j][i],j == H-1 ? '\n' : ' ');
    return 0;
}