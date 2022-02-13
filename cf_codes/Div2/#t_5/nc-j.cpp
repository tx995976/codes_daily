#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

std::deque<int> nums;

int main(){
    int n,m,t,val;
    scanf(" %d %d",&n,&m);
    for(int i = 1;i <= m;i++){
        scanf(" %d",&t);
        switch(t){
            case 1:
                scanf(" %d",&val);
                nums.push_front(val);
                break;
            case 2:
                nums.pop_front();
                break;
            case 3:
                scanf(" %d",&val);
                nums.push_back(val);
                break;
            case 4:
                nums.pop_back();
                break;
            case 5:
                std::reverse(nums.begin(),nums.end());
                break;
            case 6:{
                printf("%d\n",nums.size());
                int i = 1;
                for(auto it : nums){
                    printf("%d%c",it,i == nums.size() ? '\n' : ' ');
                    i++;
                }
                break;
            }
            case 7:{
                std::sort(nums.begin(),nums.end());
                break;
            }
        }
    }

    return 0;
}