#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include <vector>

std::deque<int> stk;
std::vector<int> nums,que;
int n,ans = 0,temp;

int main(){
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %d",&temp);
        nums.push_back(temp);
    }
    for(int i = 1;i <= n;i++){
        scanf(" %d",&temp);
        que.push_back(temp);
    }
    int pos_q = 0,size_q = que.size();
    for(int pos_n = 0;pos_n < n && pos_q < size_q;){
        while(!stk.empty()){
            if(que.front() == que[pos_q]){
                stk.pop_front();
                pos_q++;
                ans++;
            }
        }
        stk.push_front(nums[pos_n++]);
    }
    printf("%d\n",ans == size_q ? ans : 0);
    return 0;
}
