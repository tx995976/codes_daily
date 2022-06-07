# ABC248

## D.Range Count Query

按升序记录每个数字出现的位置,在给定L,R,X后.
符合条件的位置在  upper_bound(R) ~ lower_bound(L) 中
计数即为答案.

```cpp
const int max_n = 2e5+10;
std::vector qu(max_n,std::vector<int>());
int N,Q,L,R,X,ans;
bool flag = 0;

int main(){
    int a;
    scanf(" %d",&N);
    for(int i = 1;i <= N;i++){
        scanf(" %d",&a);
        qu[a].push_back(i);
    }
    scanf(" %d",&Q);
    while(Q--){
        scanf(" %d %d %d",&L,&R,&X);
        ans = 0;
        if(!qu[X].empty()){
            int l = std::lower_bound(qu[X].begin(),qu[X].end(),L) - qu[X].begin();
            int r = std::upper_bound(qu[X].begin(),qu[X].end(),R) - qu[X].begin();
            ans = r-l;
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

## E.K-colinear Line

K = 1 时,显然有无数条直线.
K > 1 时,枚举两点作为直线,再判断其余点是否在该直线上,若是加入点集.
当点集大小 >= K 时,判断任意两点构成的直线是否已统计过,若无则 ans += 1,并将该两点构成的直线标记为已统计.

```cpp
using ll = long long;
const int max_n = 300;

ll dx[max_n],dy[max_n];
bool flag[max_n][max_n];
int n,k,cnt,ans=0;
std::vector<int> p_list;

bool judge(int p1,int p2,int p3){
    ll k1 = (dy[p2] - dy[p1]) * (dx[p3] - dx[p1]);
    ll k2 = (dx[p2] - dx[p1]) * (dy[p3] - dy[p1]);
    return (k1 == k2);
}

int main(){
    scanf(" %d %d",&n,&k);
    for(int i = 0;i < n;i++)
        scanf(" %lld %lld",&dx[i],&dy[i]);
    
    if(k == 1){
        printf("Infinity\n");
        return 0;
    }
    for(int i = 0;i < n;i++)
        for(int j = i+1;j < n;j++)
            flag[i][j] = 1;

    for(int i = 0;i < n;i++)
        for(int j = i+1;j < n;j++){
            if(flag[i][j]){
                cnt = 2;
                p_list.clear();
                p_list.push_back(i);
                p_list.push_back(j);
                for(int di = j+1;di < n;di++){
                    if(judge(i,j,di)){
                        cnt++;
                        p_list.push_back(di);
                    }
                }
                for(int di = 0;di < cnt;di++)
                    for(int dj = di+1;dj < cnt;dj++)
                        flag[p_list[di]][p_list[dj]] = 0;
                if(cnt >= k)
                    ans++;
            }
        }
    printf("%d\n",ans);
    return 0;
}
```

## F.Keep Connect
```cpp
```