#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e5+10;

struct num_low{
    int num,low;
};

int nums = 0;
int ans[max_n];
num_low array[max_n];

bool cmp_low(const num_low &l,const num_low &r){
    return l.low > r.low;
}

int main(){
    int sum,limit,flag = 0;
    scanf(" %d %d",&sum,&limit);
    for(int i = 1;i <= limit;i++){
        array[i].num = i;
        array[i].low = i&(-i);
    }
    std::sort(array+1,array+1+limit,cmp_low);
    for(int i = 1;i <= limit;i++){
        if(array[i].low <= sum){
            sum -= array[i].low;
            ans[++nums] = array[i].num;
        }
        if(sum == 0){
            flag = 1;
            break;
        }
    }
    printf("%d\n",flag == 0 ? -1 : nums);
    if(flag)
        for(int i = 1;i <= nums;i++)
            printf("%d%c",ans[i],i == nums ? '\n' : ' ');
    return 0;
}
//tx995976