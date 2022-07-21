#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

const int defat_window = 3;
const int max_window = 5;
const int max_que = 7;

int rod,temp;
std::vector<int> nums;
std::deque<std::pair<int,int>> que; 

void print_que(int n,int t_now){
    if(n > que.size())
        n = que.size();
    for(int i = 1;i <= n;i++){
        printf("%d : %d\n",que.front().first,t_now-que.front().second);
        que.pop_front();
    }
    //printf("\n");
}

int main(){
    scanf(" %d",&rod);
    for(int i = 1;i <= rod;i++){
        scanf(" %d",&temp);
        nums.push_back(temp);
    }
    int window = defat_window,id = 1,time;

    for(time = 0;time < rod;time++){
        //客户到达
        int num_i = nums[time];
        for(int i = 1;i <= num_i;i++)
            que.push_back({id++,time});
            
        if((double)que.size()/window >= 7){
            int free = max_window-window;
            switch(free){
                case 0 :
                    break;
                case 1 :
                    window += 1;
                    break;
                case 2:
                    window += ((double)que.size()/(window+1) >= 7) ? 2 : 1;
                    break;
            }
        }
        //开始服务
        print_que(window,time);
        //再调整
        if((double)que.size()/window < 7 && window > defat_window)
            window -= 1;
    }
    while(!que.empty()){
        print_que(window,time++);
        if((double)que.size()/window < 7 && window > defat_window)
            window -= 1;
    }
    return 0;
}
