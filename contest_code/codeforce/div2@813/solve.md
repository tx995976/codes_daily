# cf_div2@813 

## d. [Empty Graph](https://codeforces.com/contest/1712/problem/D)

显然图的直径为$\underset{1\eqslantless i\eqslantless {n-1}}{\max} d(i,i+1)$  
对于$d(u,v)$,有$d(u,v) = \min(\min(a_u...a_v),2 \cdot \min(a_1...a_n))$  
前者是$\min(a_1...a_n)$在 $a_u..a_v$中,后者为不在$a_u..a_v$中,$\min((1,u)+(1,v),(u,n)+(v,n))$取得最小   
可以将任何数变为$1...10^9$ $k$次  
使用二分查找,验证当前答案合法时需要最少操作次数  

```cpp
const int max_n = 1e5+10;
const int inf = 1e9;

int a[max_n],b[max_n];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        int l = 1, r = inf,ans = 1;
        while(l <= r){
            int mid = (r+l)/2,cnt = 0;
            for(int i = 1; i <= n; i++){
                b[i] = a[i];
                if(b[i]*2 < mid){
                    cnt++;
                    b[i] = inf;
                }
            }
            int f1=1,f2=1;
            for(int i = 1; i <= n; i++){
                if(b[i] >= mid)
                    f1 = 0;
                if(i < n && std::min(b[i],b[i+1]) >= mid)
                    f2 = 0;
            }
            cnt += f1+f2;
            if(cnt <= k){
                l = mid+1;
                ans = mid;
            }
            else
                r = mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
```