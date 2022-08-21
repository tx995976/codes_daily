# arc143

## C. [Piles of Pebbles](https://atcoder.jp/contests/arc143/tasks/arc143_c)

对所有$A_i$ 做$\bmod{(X+Y)}$ (每人一次只能拿X|Y)  
如果所有$A_i < X$代表先手在最后一次无堆可取,告负  
对于$X \eqslantless Y$时 如果有一个$A_i \eqslantgtr X$代表先手最后一次取完后后手无堆可取  
如果$X > Y$时 出现$X < A_i \eqslantless Y$ 代表后手取完最后一次先手将无堆可取
```cpp{output="text"}
const int max_n = 2e5+10;

int main(){
    int n,x,y;
    scanf("%d %d %d", &n,&x,&y);
    std::vector<int> arr(n+1);
    bool flag = 0,win = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        arr[i] %= x+y;`
        if(arr[i] >= x)
            flag = 1;
        if(x > y && arr[i] < x && arr[i] >= y){
            win = 1;
            break;
        }
    }
    if(!flag && !win)
        win = 1;
    printf("%s\n",win ? "Second" : "First");
    return 0;
}
```

[记录](https://atcoder.jp/contests/arc143/submissions/me?f.Task=&f.LanguageName=&f.Status=&f.User=tx995976)