# arc@140

## c. [ABS Permutation (LIS ver.)](https://atcoder.jp/contests/arc140/tasks/arc140_c)

题意:对$1...n$排列出以$x$为开头的$P =(P_1...P_n) ,p_1 = x$  
能得到序列$A = (A_1...A_n),A_i = |P_i-P_{i+1}|$  
求出能得到令$A$有最长严格递增序列的$P$

先假设$P = (1...n)$  
$x$将$P$分为两部分$L = (L_m...L_1,x),R = (R_1...R_c)$  
显然$L$与$R$长度相等时 
$P = (x,R_1,L_1,R_2...L_m,R_c)$是符合条件的答案    

不同时,从$m=n/2$ 开始,长度为$(n-1)$的序列$P = (m,m-1,m+1,...)$,在$m_i = x$处将$m_i...m_{n-1}$加$1$,可以在不影响递增下得到最长序列 $P_m = (x,P)$   

```cpp
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    std::vector<int> arr(n-1);
    int m = n/2,d = 1;
    if(n%2 == 0 && x == n/2)
        d = -1;
    for(int i = 0;i < n-1;i++){
        arr[i] = m;
        m += d;
        if(d > 0)
            d += 1;
        else
            d -= 1;
        d *= -1;
    }
    printf("%d ",x);
    for(int i : arr)
        printf("%d ",i < x ? i : i+1);
    return 0;

}
```