#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<cstring>
#include<bitset>

const int max_n = 2010;
int n,m;

struct {int x,y;} pos[max_n];
struct di {
    int dis,a,b;
    bool operator < (const di &r){
        return dis < r.dis;
    }
} A[max_n*max_n];

std::bitset<max_n> pan[max_n];

class prime_ruler{
public:
    std::vector<bool> flag_prime;

    void prime_list(int range){
        flag_prime.resize(range+1,0);
        flag_prime[1]=1;
        for(int i = 2;i <= range;i++){
            if(flag_prime[i])
                continue;
            for(int j=i+i;j <= range;j+=i)
                flag_prime[j]=1;
        }
    }
};

int main(){

    prime_ruler prime;
    prime.prime_list(2e5+10);

    int t;
    scanf("%d",&t);
    while(t--){
        long long ans = 0ll;
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;i++){
            pan[i].reset();
            scanf("%d %d",&pos[i].x,&pos[i].y);
        }   
        int cnt = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++){
                A[++cnt] = (di){std::abs(pos[i].x-pos[j].x)+std::abs(pos[i].y-pos[j].y),i,j};
            }
        std::sort(A+1,A+1+cnt);
        for(int i = 1;i <= cnt;i++){
            if(!prime.flag_prime[A[i].dis])
                ans += (pan[A[i].a]^pan[A[i].b]).count();
            pan[A[i].a][A[i].b] = 1;
            pan[A[i].b][A[i].a] = 1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}