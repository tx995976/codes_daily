//#图论
//@并查集
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 5e5+10;
int N,M,E,Q;

struct funion{
        std::vector<int> father,size;
        funion(int n) : father(n),size(n){
            for(int i = 0;i < n;i++){
                father[i] = i;
                size[i] = 1;
            }
        }
        //状态压缩
        int find_zip(int x){
            if(x != father[x])
                father[x] = find_zip(father[x]);
            return father[x];
        }
        //不压缩
        int find(int x){
            x = father[x] == x ? x : find(x);
            return x;
        }
        void unionset(int a,int b){
            a = find_zip(a);
            b = find_zip(b);
            if(a != b){
                father[a] = b;
                size[b] += size[a];
                size[a] = 0;
            }
        }
    };

bool adg[max_n];
struct ed{int u,v;};
std::vector<ed> edge;

int main(){
    scanf("%d %d %d",&N,&M,&E);
    int u,v;

    for(int i = 1;i <= E;i++){
        scanf("%d %d",&u,&v);
        u = u > N ? N+1 : u;
        v = v > N ? N+1 : v;
        edge.push_back(ed{u,v});
    }

    scanf("%d",&Q);
    std::vector<int> q(Q),ans(Q+1);
    for(int &i : q){
        scanf("%d",&i);
        //printf("ed:%d\n",i);
        adg[i] = 1;
    }
    funion tree(max_n);
    for(int i = 1;i <= E;i++){
        if(adg[i])
            continue;
        auto [u,v] = edge[i-1];
        if(tree.find_zip(u) == N+1)
            std::swap(u,v);
        tree.unionset(u,v);
    }

    ans[Q] = tree.size[N+1]-1;
    for(int i = Q-1;i > 0;i--){
        auto [u,v] = edge[(q[i]-1)];
        //printf("get: %d %d\n",u,v);
        if(tree.find_zip(u) == N+1)
            std::swap(u,v);
        tree.unionset(u,v);
        ans[i] = tree.size[N+1]-1;
    }
    for(int i = 1;i <= Q;i++)
        printf("%d\n",ans[i]);

    return 0;
}