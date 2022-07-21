/* 
#数学/鸽巢原理
#图论
*/
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 3e5+10; 

std::vector<int> graph[max_n+3010];
int Matix[3010][3010];
int S,T,M;
int x1,x2,y1,y2;
bool flag = false;

void search(){
    for(int i=1;i <= S;i++){
        for(auto ii : graph[i])
            for(auto ij : graph[i]){
                if(ii == ij)
                    continue;
                else if(ii > S && ij > S){
                    int t1 = ii - S,t2 = ij - S;
                    if(Matix[t1][t2] == 0)
                        Matix[t1][t2] = Matix[t2][t1] = i;
                    else if(Matix[t1][t2] != i){
                        x1 = ii,x2 = ij,y1 = Matix[t1][t2],y2 = i;
                        flag = true;
                        return;
                    }
                }
            }
    }
}

int main(){
    scanf("%d %d %d",&S,&T,&M);
    int u,v;
    for(int i=0;i<M;i++){
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    search();
    if(flag)
        printf("%d %d %d %d\n",x1,y1,x2,y2);
    else
        printf("-1\n");
    return 0;
}