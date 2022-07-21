#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e5+10;
std::deque<int> length;
int n,deep[max_n];
long long nums[max_n];
long long ans = 0;

int main(){
    scanf(" %d",&n);
    while(n != 0){
        ans = 0ll;
        length.clear();
        for(int i = 1;i <= n;i++){
            scanf(" %d",&nums[i]);
        }
        nums[n+1] = 0;
        for(int i = 1;i <= n+1;i++){
            int depth = i;  //记录可达点
            while(!length.empty() && nums[i] < nums[length.back()]){
                ans = std::max(ans,(long long)(i - deep[length.back()]) * nums[length.back()]);
                depth = deep[length.back()];
                length.pop_back();
            }
            length.push_back(i);
            deep[i] = depth; //保证区间能取最大
        }
        
        printf("%lld\n",ans);
        scanf(" %d",&n);
    }

    return 0;
}