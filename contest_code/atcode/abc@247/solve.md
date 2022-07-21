# ABC247

## E.MAX MIN

对于寻找满足要求的`[L,R]`对,可以转换成对应区间 $A_L\dots A_R$ 的个数  
当我们找到所有满足 $Y<= A_k<= X$ 的区间后  
由集合的相关知识可以知道

包含`X`和`Y`的区间数$=$
全集$-$不包含`X`的区间数$-$不包含`Y`的区间数$+$不包含`X`和`Y`的区间数  

而我们知道全集中$Y<= A_k<= X$  
因此每一个包含`X`和`Y`的区间都是满足要求的`[L,R]`对

```cpp
using ll = long long;
const int max_n = 2e5+10;

int X,Y,N;
ll ans=0ll;
int _XY[max_n],_X[max_n],_Y[max_n],R[max_n],A[max_n];

ll get_seq(int a[]){
    ll res=0,len=0;
    for(int i = 1;i <= N;i++){
        if(a[i] == 1){
            res += len * (len + 1)/2;
            len = 0ll;
        }
        else
            len += 1ll;
    }
    res += len * (len + 1)/2;
    return res;
}

int main(){
    scanf(" %d %d %d",&N,&X,&Y);
    for(int i = 1;i <= N;i++)
        scanf(" %d",&A[i]);
    for(int i = 1;i <= N;i++){
        if(!(Y <= A[i] && A[i] <= X)){
           _XY[i]=_X[i]=_Y[i]=R[i]=1; 
        }
        if(A[i] == X)
            _X[i]=_XY[i]=1;
        if(A[i] == Y)
            _Y[i]=_XY[i]=1;
    }
    ans = get_seq(R)-get_seq(_X)-get_seq(_Y)+get_seq(_XY);
    printf("%lld\n",ans);
    return 0;
}
```
