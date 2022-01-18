#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 1e6+10;
std::deque<int> num_d;
int num[max_n];

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i <= n;i++)
        scanf("%d",&num[i]);
    //min
    for(int i = 1;i <= n ;i++){
        while(!num_d.empty() && num[num_d.back()] > num[i])
            num_d.pop_back();
        num_d.push_back(i);
        while(!num_d.empty() && num_d.front() < i-k+1)
            num_d.pop_front();
        if(i >= k)
            printf("%d%c",num[num_d.front()],i == n? '\n' : ' ');
    }
    num_d.clear();
    for(int i = 1;i <= n ;i++){
        while(!num_d.empty() && num[num_d.back()] < num[i])
            num_d.pop_back();
        num_d.push_back(i);
        while(!num_d.empty() && num_d.front() < i-k+1)
            num_d.pop_front();
        if(i >= k)
            printf("%d%c",num[num_d.front()],i == n? '\n' : ' ');
    }

    return 0;
}