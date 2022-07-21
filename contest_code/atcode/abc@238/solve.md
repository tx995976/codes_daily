# atcode ABC_238

## E.Range Sums
题目给出得元素和可以看做成 i[r] - i[l-1] (i[x]代表前x元素之和)  
要能够得到完整序列,即i[N] - i[0]  
将 0~N 看作顶点, 有Q条无向边链接这些顶点  
只要 0-N 可达即可.  
可以使用bfs或并查集来解决.
```cpp
const int max_n = 3e5+10;
int N,Q;

struct my_union{
        int father[max_n] = {0};
        my_union(int N){
            for(int i = 0;i < N;i++){
                father[i] = i;
            }
        }   
        int find(int x){
            if(x != father[x])
                father[x] = find(father[x]);
            return father[x];
        }
        void unionset(int a,int b){
            a = find(a);
            b = find(b);
            if(a == b)
                return;
            father[a] = b;
        }
        bool judge(int a,int b){
            return find(a) == find(b);
        }
    };

int main(){
    scanf(" %d %d",&N,&Q);
    my_union tree(N+1);
    int l,r;
    for(int i = 1;i <= Q;i++){
        scanf(" %d %d",&l,&r);
        tree.unionset(l-1,r);
    }
    printf("%s\n",tree.judge(0,N) ? "Yes" : "No");
    return 0;
}
```