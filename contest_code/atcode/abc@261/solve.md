# ABC261

### E.Many Operations

题意:给定n个操作,包含对$c$按位和,按位或,按位异或  
$f(n)$ 表示对$c$依次进行$1...n$操作,求$f(1)...f(n)$  

朴素做法显然超时($n \eqslantless 2e5 $)  
如果按位处理,可以有 $map[2]$ = {$0,1$}  
当操作$1$ 为 按位和 有, $f[2]$ = {$0$&$A[j][i]$,$1$&$A[j][i]$}  
$map[2]$ = {$f(map[0]),f(map[1])$}  
$c$的第一位为$c_0$ , 那么$map[c_0]$ 即为$c_0$  在操作$1$后的对应值  
同样求得操作$2$的$f[2]$,接着操作$1$所得的$map[2]$为$c_0$在操作$1.2$后的对应值  
这样可以便可以较快求出$f(1)...f(n)$ 

```cpp
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
```

### F.Sorting Color Balls

题意:颜色相同的球交换无消耗,否则消耗$1$  
求最少交换代价让序列成为不降序序列  

可以知道最少交换次数是序列中逆序对的数量  
将颜色相同的球分为一组,那么其中的交换是无消耗的  
那么最少代价即为: 总交换次数 - 相同颜色球组中交换次数  
使用树状数组来快速求出逆序对数量


```cpp
const int max_n = 3e5+10;
int color[max_n],d;
std::vector<int> id[max_n];

using binary_tree = temp::binary_tree;

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&color[i]);
    for(int i = 0;i < n;i++){
        scanf("%d",&d);
        id[0].push_back(d);
        id[color[i]].push_back(d);
    }
    long long ans = 0ll;
    binary_tree<long long> sm(n);
    for(int i = 0;i <= n;i++){
        for(auto it : id[i]){
            if(i == 0)
                ans += sm.query_range(it+1,n);
            else
                ans -= sm.query_range(it+1,n);
            sm.add(it,1ll);
        }
        for(auto it : id[i])
            sm.add(it,-1ll);
    }
    printf("%lld\n",ans);
    return 0;
}
```
![](ac.png)