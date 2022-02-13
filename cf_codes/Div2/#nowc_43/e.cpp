#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

using ll = long long;

const int n = 10, _mod = 1e9 + 7;

ll cnt[n];
ll num_mod[n][3];

int main(){
    for(int i = 1;i <= 9;i++)
        scanf(" %d",&cnt[i]);

    for(int i = 0;i <= 9;i++)
        num_mod[i][0] = 1;
        
    for(int i = 1;i <= 9;i++){
        int mod_0, mod_1, mod_2;
        if(i % 3 == 1){
            mod_1 = (cnt[i] + 2) / 3;
            mod_2 = (cnt[i] + 1) / 3;
            mod_0 = cnt[i] / 3;
        }
        else if(i % 3 == 2){
            mod_1 = (cnt[i] + 1) / 3;
            mod_2 = (cnt[i] + 2) / 3;
            mod_0 = cnt[i] / 3;
        }
        else{
            mod_1 = 0;
            mod_2 = 0;
            mod_0 = cnt[i];
        }

        num_mod[i][0] = num_mod[i-1][0] * (mod_0+1) + num_mod[i-1][1] * (mod_2) + num_mod[i-1][2] * mod_1;
        num_mod[i][1] = num_mod[i-1][1] + num_mod[i-1][0] * mod_1 + num_mod[i-1][1] * mod_0 + num_mod[i-1][2] * mod_2;
        num_mod[i][2] = num_mod[i-1][2] + num_mod[i-1][0] * mod_2 + num_mod[i-1][1] * mod_1 + num_mod[i-1][2] * mod_0;

        num_mod[i][0] %= _mod;
        num_mod[i][1] %= _mod;
        num_mod[i][2] %= _mod;
    }

    printf("%lld\n",num_mod[9][0]);
    return 0;
}