# ABC260

### E. At Least One 

朴素枚举所有区间并验证需要 $ m^2n $ 时间,考虑优化  
考虑滑动窗口的思想,已知$ [L,R] $为满足条件的序列  
那么对于$1 \eqslantless i \eqslantless L$, $R \eqslantless j \eqslantless M$  
$[i,j]$同样为满足条件的序列.  
因此从$[L,R]$出发, 找到所有满足条件的最小区间序列集.  
再求出它们的扩展序列区间就得到所有满足条件的区间
```cpp
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
```

### F. Find 4-cycle

找到一个四点构成的回路,已知$V_1$,$V_2$都是独立集(集内点互相无边)  
存储点的邻接表$graph$后,从$V_1$中的点出发,遍历$graph[V]$,$V \in V_1$.  
$A,B \in graph[V],A \not ={B}$  
当$A,B \in V_2$ 时  
$Matix[A][B] = 0$时,$Matix[A][B] = V$(A,B点首次与V点相连)  
$Matix[A][B] = Z$时,(A,B点与Z点首次相连后再与V点相连)  
$A,B \in V_2$, $Z,V \in V_1$因此(A,B,Z,V)形成四点回路.

```cpp
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
```

@import "ac.png"  





