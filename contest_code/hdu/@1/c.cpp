//#动态规划
//@二进制
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>

int T,ans;
std::bitset<1025> t1[1025],t2[1025];

int main(){
    scanf("%d",&T);
    int n,m,v,w;
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i = 0;i < 1024;i++)
            t1[i].reset();
        t1[0][0] = 1;

        for(int i = 1;i <= n;i++){
            scanf("%d %d",&v,&w);
            for(int j = 0;j < 1024;j++){
                t2[j] = t1[j];
                t2[j] <<= v;
            }
            for(int j = 0;j < 1024;j++){
                t1[j] |=  t2[j^w];
            }
        }
            
        ans = -1;
        for(int i = 1023;i >= 0 ;i--)
            if(t1[i][m]){
                ans = i;
                break;
            }
        printf("%d\n",ans);
    }
    return 0;
}