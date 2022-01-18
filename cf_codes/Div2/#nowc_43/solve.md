# 牛客小白月赛43

## A

按题意打表发现规律,即result = a;
```cpp
//打表代码
void table(){          
    int n = 1e3;
    for(int i = 1 ; i <= n;i++){
        nums.clear();
        for(int j = 1;j <= i;j++){
            if((i % j) == 0)
                nums.push_back(j);
        }
        int len = nums.size();
        if((nums[len-1] % nums[len/2]) == 0)
            printf("%d\n",i);
    }

}
//
int main(){
    int t,n;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++){
        scanf("%d",&n);
        printf("%d\n",n);
    }
    
    return 0;
}

```

## B

首先处理 a == tar || b == tar ,每次操作后a b翻倍后必为偶数  
所以tar为奇数时,a b通过操作必不可得  
当tar为偶数时,通过n次操作使**a+b** > **tar**过程中,一定能通过操作获得**tar**含量.

```cpp
using ll = long long;
ll a,b,tar,temp;
int T,cnt;

int main(){
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%lld %lld %lld",&a,&b,&tar);
        //
        if(a == tar || b == tar){
            printf("0\n");
            continue;
        }
        //
        if(tar&1){
            printf("-1\n");
            continue;
        }
        temp = (a + b)<<1;
        cnt = 1;
        while(temp < tar){
            cnt++;
            temp <<= 1;
        }
        
        printf("%d\n",cnt);
    }

    return 0;
}
```

## C
