#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e6+10;
std::deque<int> stack;
int array[max_n],max[max_n] = {0};


int main(){
    int n,temp;
    scanf(" %d",&n);
    int pos = n;
    for(int i = 1;i <= n;i++){
        scanf(" %d",&array[i]);
    }
    for(int i = n;i >= 1;i--){
        max[i] = std::max(max[i+1],array[i]);
    }
    for(int i = 1;i <= n;i++){
        stack.push_back(array[i]);
        while(!stack.empty() && stack.back() > max[i+1]){
            printf("%d ",stack.back());
            stack.pop_back();
        }
    }
    while(!stack.empty()){
        printf("%d ",stack.back());
        stack.pop_back();
    }
    printf("\n");
    return 0;
}