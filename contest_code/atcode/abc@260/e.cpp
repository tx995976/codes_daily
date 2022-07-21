#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 2e5+10;

int N,M;
int map_seq[max_n];
std::vector<int> need[max_n];
int ans[max_n];

int main(){
    int a,b;
    scanf("%d %d",&N,&M);    
    for(int i = 1;i <= N;i++){
        scanf("%d %d",&a,&b);
        need[a].push_back(i);
        need[b].push_back(i);
    }
    int cnt_zero = N;
    int L = 1,R = 1;

    for(;L <= M;){
        while(R <= M && cnt_zero != 0){
            for(auto it : need[R]){
                if(map_seq[it] == 0)
                    cnt_zero--;
                map_seq[it] += 1;
            }
            R++;
        }
        if(cnt_zero != 0)
            break;
        //差分
        ans[R-L]++;
        ans[M-L+2]--;

        for(auto it : need[L]){
            map_seq[it] -= 1;
            if(map_seq[it] == 0)
                cnt_zero++;
        }
        L++;
    }
    for(int i = 1;i <= M;i++){
        ans[i] += ans[i-1];
        printf("%d ",ans[i]);
    }

    return 0;
}