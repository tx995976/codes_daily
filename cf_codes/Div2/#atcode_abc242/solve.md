# ABC242

## d.ABC Transform
A->BC
B->CA
C->AC

ABC
BCCAAC
C....
A..
可以发现第一位是周期变化的.  
S[t][k] 表示S串在第t次变化的k位字母,有:  
- S[t][k] = 'A'+('A'-S[t-1][k/2]+(k%2+1))  

递归写出即可

```cpp
using ll = int64_t;
std::string in;
int Q;
ll t,k;

char per(char x,ll t_){
    return ('A'+(x-'A'+t_)%3);
}

char solve(ll ti,ll ki){
    if(ti == 0)
        return in[ki];
    if(ki == 0)
        return per(in[0],ti);
    return per(solve(ti-1,ki/2),ki%2+1);
}

int main(){
    std::cin>>in;
    scanf(" %d",&Q);
    while(Q--){
        scanf(" %lld %lld",&t,&k);
        printf("%c\n",solve(t,k-1));
    }
    return 0;
}
```

## E.(∀x∀)


```cpp
```