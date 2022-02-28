#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<cstring>

const int max_n = 2e2+10;
int a,b,c,d;
bool flag = 0;

namespace my_tem{
    bool flag_prime[max_n];
    int prime[max_n];

    int prime_list(int range)
    {
        int cnt=0;
        std::memset(flag_prime,true,sizeof(flag_prime));
        for(int i=2;i<=range;i++)
        {
            if(flag_prime[i])
            prime[++cnt]=i;   // begin:prime[1]
            for(int j=1;j<=cnt;j++){
                if(i*prime[j]>range)
                    break;
                flag_prime[i*prime[j]]=0;
                if(i%prime[j]==0)
                    break;
            }
        }
        return cnt;
    }
}

int main(){
    scanf(" %d %d %d %d",&a,&b,&c,&d);
    my_tem::prime_list(max_n);
    for(int i = a;i <= b;i++){
        flag = 1;
        for(int j = c;j <= d;j++){
            if(my_tem::flag_prime[i+j])
                flag = 0;
        }
        if(flag)
            break;
        else
            flag = 0;
    }

    printf("%s\n",flag ? "Takahashi" : "Aoki");
    return 0;
}