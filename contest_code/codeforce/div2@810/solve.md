# cf_div2@810

## c. [Color the Picture](https://codeforces.com/contest/1711/problem/C)

希望至少3个邻居相同颜色,那么对邻居继续递推,相同颜色应至少为2行或2列  
直接求出各颜色能涂上的(行/列)数($\eqslantgtr 2$)总和,大于(列/行)数时可行  
同时若(行/列)数为奇数,需要至少有一颜色涂出的(列/行)数 $> 2$  

```cpp
using ll = long long;
const int max_n = 1e5+10;
int ai[max_n];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for(int i = 1; i <= k; i++)
            scanf("%d",&ai[i]);

        ll ev = 0ll;
        bool flag = 0,ans = 0;

        // m 
        for(int i = 1; i <= k; i++){
            int num = ai[i]/m;
            if(num >= 2)
                ev += num;
            if(num > 2)
                flag = 1;
        }
        if(ev >= n && (flag || n%2 == 0))
            ans = 1;
            
        if(!ans){
            flag = 0;
            ev = 0ll;
            // n 
            for(int i = 1; i <= k; i++){
                int num = ai[i]/n;
                if(num >= 2)
                    ev += num;
                if(num > 2)
                    flag = 1;
            }
            if(ev >= m && (flag || m%2 == 0))
                ans = 1;
        }
        printf("%s\n",ans ? "Yes" : "No");
    }
    return 0;
}
```