#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 3e5+10;
int N,k;
bool num[max_n];

int main(){
    scanf(" %d %d",&N,&k);
    if(N < 2*k)
        printf("-1\n");
    else{
        int em = 1;
        for(int i=1;i <= N;i++){
            int t = i + k;
            if(t > N || num[t] || t + k <= N){
                t = em;
                if(std::abs(em - i) < k)
                    t = i + k;
            }
            printf("%d ",t);
            num[t] = 1;
            while(num[em])
                em++;
        }
        printf("\n");
    }
    return 0;
}