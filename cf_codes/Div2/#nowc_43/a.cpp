#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include <vector>

std::vector<int> nums;

void table(){
    int n = 1e3;
    for(int i = 1 ; i <= n;i++){
        nums.clear();
        for(int j = 1;j <= i;j++){
            if((i % j) == 0)
                nums.push_back(j);
        }
        int len = nums.size();
        if((nums[len-1] % nums[len/2]) == 0)
            printf("%d\n",i);
    }

}


int main(){
    int t,n;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++){
        scanf("%d",&n);
        printf("%d\n",n);
    }
    
    return 0;
}