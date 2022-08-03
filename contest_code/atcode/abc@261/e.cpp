//#数学/位运算
//@二进制
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<bitset>

const int max_n = 2e5+10;
int opera[max_n];
std::bitset<32> A[max_n],ans[max_n],c;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    c = std::bitset<32>(m);

    for(int i = 1;i <= n;i++){
        scanf("%d %d",&opera[i],&m);
        A[i] = std::bitset<32>(m);
        //printf("%u\n",A[i]);
    }

    for(int i = 0;i < 30;i++){
        std::vector<int> map = {0,1};
        int bit_i = c[i];

        for(int j = 1;j <= n;j++){
            std::vector<int> nmap = {0,1};
            if(opera[j] == 1)
                nmap = {0&A[j][i],1&A[j][i]};
            else if(opera[j] == 2)
                nmap = {0|A[j][i],1|A[j][i]}; 
            else if(opera[j] == 3)
                nmap = {0^A[j][i],1^A[j][i]};
            //printf("n:%d %d\n",nmap[0],nmap[1]);
            map = {nmap[map[0]],nmap[map[1]]};
            //printf("%d %d\n",map[0],map[1]);
            bit_i = map[bit_i];
            //printf("%d\n",bit_i);
            ans[j].set(i,(bool)bit_i);
            //printf("%d : %d %u\n",j,i,ans[j]);
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%u\n",ans[i]);
    }
    return 0;
}