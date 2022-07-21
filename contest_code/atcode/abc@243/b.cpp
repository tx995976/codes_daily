#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<unordered_map>

struct b_pair{
    int a = 0,b = 0;
};

std::unordered_map<int,b_pair> n_map;

int N;
int ai,bi;
int ans_1,ans_2;

int main(){
    scanf(" %d",&N);
    for(int i = 1;i <= N;i++){
        scanf(" %d",&ai);
        n_map[ai].a = i;
    }
    for(int i = 1;i <= N;i++){
        scanf(" %d",&bi);
        n_map[bi].b = i;
    }
    for(auto it : n_map){
        if(it.second.a == 0 || it.second.b == 0)
            continue;
        if(it.second.a == it.second.b)
            ans_1++;
        else
            ans_2++;
    }
    printf("%d\n%d\n",ans_1,ans_2);
    return 0;
}