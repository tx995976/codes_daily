#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<set>

const int max_n = 2e5+10;

int N,K;
int card[max_n];
int move[max_n];
int card_plie[max_n] = {0};
int size_plie[max_n];
int plie_step[max_n] = {0};
int pie = 1,step = 1;

std::set<int> que;

int main(){
    scanf("%d %d",&N,&K);
    for(int i = 1; i <= N; i++){
        scanf("%d",&card[i]);
    }
    if(K != 1){
        for(int i = 1; i <= N; i++){
            int c_i = card[i];
            int *pos = &card_plie[c_i];
            auto it = que.lower_bound(c_i);
            que.insert(c_i);
            if(it != que.end()){
                *pos = card_plie[*it];
                if(++size_plie[*pos] == K){
                    plie_step[*pos] = step;
                    que.erase(c_i);
                }
                que.erase(*it);
            }
            else{
                *pos= pie++;
                size_plie[*pos] = 1;
            }
            step++;
        }
        for(int i = 1; i <= N; i++)
            move[card[i]] = plie_step[card_plie[card[i]]] == 0 ? -1 : plie_step[card_plie[card[i]]];
    }
    else{
        for(int i = 1; i <= N; i++)
            move[card[i]] = i;
    }
    for(int i = 1; i <= N; i++)
        printf("%d\n",move[i]);
    return 0;
}