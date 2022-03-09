#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

std::vector<std::vector<int>> nums;
int n,temp,direct = 1;


int main(){
    scanf(" %d",&n);
    nums.resize(n+1);
    for(int i = 1;i <= n;i++)
        nums[i].resize(n+1);
    int st = 1;
    for(int i = 1;i <= (2*n-1);i++){
        direct ^= 1;
        int y = i > n ? n : i;
        int x = i >= n ? (i+1)-n : 1;
        while(y > 0 && x < n+1){
            if(direct)
                nums[y][x] = st++;
            else
                nums[x][y] = st++;
            y--,x++;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            printf("%-4d",nums[i][j]);
        }
        printf("\n");
    }
    return 0;
}