# cf_div2@812

## D. [Tournament Countdown](https://codeforces.com/contest/1713/problem/D)

如果将赛程相连的4人看作一组,我们能通过询问$2$次得到胜者  
通过这个操作,能将范围从$1^n$缩小到$1^{n-2}$,询问$1^{n-1}$次  
对于$n \eqslantgtr 3$,总次数为$1+\sum{1^{n-1}}(;n > 2;n = n-2) \eqslantless \lceil \frac{1}{3} \cdot 1^{n+1} \rceil$


```cpp
int judge(std::vector<int> &p){
    printf("? %d %d\n",p[0],p[2]); fflush(stdout);
    int res;
    scanf("%d",&res);
    if(res == 1){
        printf("? %d %d\n",p[0],p[3]); fflush(stdout);
        scanf("%d",&res);
        if(res == 1)
            return p[0];
        return p[3];
    }
    else if(res == 2){
        printf("? %d %d\n",p[1],p[2]); fflush(stdout);
        scanf("%d",&res);
        if(res == 1)
            return p[1];
        return p[2];
    }
    else{
        printf("? %d %d\n",p[1],p[3]); fflush(stdout);
        scanf("%d",&res);
        if(res == 1)
            return p[1];
        return p[3];
    }
    return 0;
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        std::vector<int> par,cp;
        for(int i = 1;i <= (1ll<<n);i++)
            par.emplace_back(i);
        while(par.size() > 2){
            while(!par.empty()){
                std::vector<int> group(4);
                group[0] = par.back();
                par.pop_back();
                group[1] = par.back();
                par.pop_back();
                group[2] = par.back();
                par.pop_back();
                group[3] = par.back();
                par.pop_back();
                int wp = judge(group);
                cp.emplace_back(wp);
            }
            par = cp;
            cp.clear();
        }
        if(par.size() == 2){
            int res;
            printf("? %d %d\n",par[0],par[1]); fflush(stdout);
            scanf("%d",&res);
            if(res == 2)
                par[0] = par[1];
        }
        printf("! %d\n",par[0]); fflush(stdout);
    }
    return 0;
}
```