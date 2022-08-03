#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<bitset>


const int max_n = 1e5+10;
int arr[max_n],opera[max_n][3];
int n,q;

std::bitset<max_n> xorbit,low,high;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&q);
        for(int i = 1;i <= n;i++)
            scanf("%d",&arr[i]);
        for(int i = 1;i <= q;i++){
            scanf("%d",&opera[i][0]);
            if(opera[i][0] == 1)
                scanf("%d %d",&opera[i][1],&opera[i][2]);
            else
                scanf("%d",&opera[i][1]);
        }

        int ans = 0;
        xorbit = 0;
        for(int i = q;i >= 1;i--){
            if(opera[i][0] == 1){
                int l = opera[i][1],r = opera[i][2];
                low = xorbit & (~std::bitset<max_n>(0) >> (max_n-r-1));
                high = xorbit & (~std::bitset<max_n>(0) << (r+1));
                xorbit = low ^ (high >> (r+1-l));
            }
            else
                xorbit.flip(opera[i][1]);
        }
        for(int i = 1;i <= n;i++)
            if(xorbit[i])
                ans ^= arr[i];
        printf("%d\n",ans);
    }
    return 0;
}