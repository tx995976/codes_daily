#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

bool flag[10];
std::deque<int> num_q;

void print(){
    for(auto it : num_q)
        printf("%d ",it);
    printf("\n");
}

void dfs(){
    if(num_q.size() == 8){
        print();
        return;
    }
    for(int i = 1;i <= 8;i++){
        if(flag[i])
            continue;
        flag[i] = 1;
        num_q.push_back(i);
        dfs();
        flag[i] = 0;
        num_q.pop_back();
    }
}

int main(){
    dfs();
    return 0;
}