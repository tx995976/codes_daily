# ABC245

## D.Polynomial division
对于 C(n+m) = A(n)B(m)  
    C(n+m-1) = A(n-1)B(m)+A(n)B(m-1)  
    ...  
有  B(m) = c(n+m)/A(n)  
    B(m-1) = (C(n+m-1)-A(n-1)B(m))/A(n)  
    B(m-2) = (C(n+m-2)-A(n-2)B(m)-A(n-1)B(m-1))/A(n)  

所以从B(m)出发向下递推,对每求得的B(i)更新C(i+(0~n)) -= B(i)*A(0~n)  
B(i) = C(i+n)/A(n)  
```cpp
const int max_n = 2e2+10;
int N,M;
int a[max_n],c[max_n],b[max_n];

int main(){
    scanf(" %d %d",&N,&M);
    for(int i = 0;i <= N;i++)
        scanf(" %d",&a[i]);
    for(int i = 0;i <= N+M;i++)
        scanf(" %d",&c[i]);
    
    for(int i = M;i >= 0;i--){
        b[i] = c[i+N] / a[N];
        for(int j = 0;j <= N;j++)
            c[i+j] -= b[i] * a[j];
    }
    for(int i = 0;i <= M;i++)
        printf("%d%c",b[i],i == M ? '\n' : ' ');
    return 0;
}
```

## E.Wrapping Chocolate
将所有箱子和巧克力按宽度降序排列,并且相同时箱子优先在前  
然后从头开始遍历  
如果是箱子,将长度记录进另一序列  
如果是巧克力,从箱子的序列中选第一个不小于巧克力长度的箱子(保证箱子宽度大于巧克力)  
如果找不到合适的箱子,则答案为否,否则为是  

```cpp
struct bc{
    int wid,length,type;
    bool operator < (const bc &r){
        return wid != r.wid ? (wid > r.wid) : (type < r.type);
    }
};

std::vector<bc> sen;
std::multiset<int> check;
int N,M;
bool flag = 0;

int main(){
    scanf(" %d %d",&N,&M);
    sen.resize(N+M);

    for(int i = 0;i < N;i++){
        scanf(" %d",&sen[i].wid);
        sen[i].type = 1;
    }
    for(int i = 0;i < N;i++)
        scanf(" %d",&sen[i].length);

    for(int i = N;i < N+M;i++){
        scanf(" %d",&sen[i].wid);
        sen[i].type = 0;
    }
    for(int i = N;i < N+M;i++)
        scanf(" %d",&sen[i].length);
        
    std::sort(sen.begin(),sen.end());    
    for(auto it : sen){
        if(it.type){
            auto l = check.lower_bound(it.length);
            if(l != check.end()){
                check.erase(l);
            }
            else{
                flag = 1;
                break;
            }
        }
        else
            check.insert(it.length);
    }

    printf("%s\n",flag ? "No" : "Yes");
    return 0;
}
```