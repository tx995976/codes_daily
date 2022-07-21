#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<list>

const int max_n = 5e5+10;
std::list<int> nums;
bool pos[max_n];

int main(){
    int n;
    char temp;
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++){
        scanf(" %c",&temp);
        pos[i] = temp == 'L' ? 0 : 1;
    }
    nums.push_back(0);
    auto it = nums.begin();
    for(int i = 1;i <= n;i++){
        if(pos[i]){
            it++;
            nums.emplace(it,i);
            it--;
        }
        else{
            nums.emplace(it,i);
            it--;
        }
    }
    for(auto it : nums)
        printf("%d ",it);
    printf("\n");
    return 0;
}