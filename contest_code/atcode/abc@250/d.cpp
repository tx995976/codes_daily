#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<cmath>

using ll = long long;
ll N,ans = 0ll;
int num_prime;


namespace alo{
    const int max_a = 1e6;
    bool flag_prime[max_a];
    int prime[max_a];

    int prime_list(int range)
    {
        int cnt=0;
        memset(flag_prime,true,sizeof(flag_prime));
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
    scanf(" %lld",&N);
    num_prime = alo::prime_list(alo::max_a);
    for(int q = 2;q <= num_prime;q++){
        ll p = alo::prime[q];
        ll th_q = p*p*p;
        int dis = 0;
        if(th_q > N)
            break;
        ll ran = std::min((N/th_q),p-1);
        for(int i = 1;i <= num_prime;i++){
            if(alo::prime[i] > ran)
                break;
            dis++;
        }
        ans += dis;
    }
    printf("%lld\n",ans);
    return 0;
}