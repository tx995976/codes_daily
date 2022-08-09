# ARC144

## b. [Gift Tax](https://atcoder.jp/contests/arc144/tasks/arc144_b)

题意:可以对序列一元素加a,另一元素减b (任意次数)  
求序列在操作后 最大 的序列最小值  

由于$a \eqslantless b$,因此任意操作后序列总和只会减少或不变  
假设最小值为$i$,那么记录 $<i$ 的数通过操作a达到 $\eqslantgtr i$的最少次数总和$a_i$  
以及 $\eqslantgtr i$ 的数通过操作b达到 $\eqslantgtr i$的最多次数总和$b_i$  
那么当$a_i \eqslantless b_i$ 表示 $i$作为最小值可行  
可以通过二分得到答案  

```cpp
using ll = long long;
int n,a,b;
ll l = 0,r = INT32_MAX;
std::vector<ll> A;

int main(){
    scanf("%d %d %d",&n,&a,&b);
    A.resize(n);
    for(int i=0;i<n;i++){
       scanf("%lld",&A[i]);
    }
    while(l < r-1){
        ll mid = (r+l)/2;
        ll ai=0,bi=0;
        for(int it : A){
            if(it >= mid)
                bi += ((ll)it-mid)/b;
            else
                ai += (mid-it+(a-1))/a;
        }
        if(ai <= bi)
            l = mid;
        else
            r = mid;
    }
    printf("%lld\n",l);
    return 0;
}
```



## c. [K Derangement](https://atcoder.jp/contests/arc144/tasks/arc144_c)

对于每个$A_i$,可取值的范围在$(A_i \eqslantless{i-k}) (A_i \eqslantgtr i+k)$  
希望字典序最小,应贪心尽量取小  
同时关注$i + 2k > N$时,$i+k$的可行位置在$A_1...A_i$ 及 $A_{i+2k}...$  
$A_1...A_{i-1}$已确定,因此只有$A_i = i+k$  

```cpp
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
```