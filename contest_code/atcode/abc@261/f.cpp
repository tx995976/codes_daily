//#数据结构/树状数组
//@逆序对
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 3e5+10;
int color[max_n],d;
std::vector<int> id[max_n];


template<class T>
    class binary_tree{
        int max_tree;
    public:
        std::vector<T> tree;
        binary_tree(int n){
            max_tree = n;
            tree.resize(n+1,0);
        }
        T lowbit(T x){
            return x & (-x);
        }
        void add(T x, T val){
            while(x <= max_tree){
                tree[x] += val;
                x += lowbit(x);
            }
        }
        T query(T x){
            T res = 0;
            while(x > 0){
                res += tree[x];
                x -= lowbit(x);
            }
            return res;
        }
        T query_range(T l, T r){
            return query(r) - query(l - 1);
        }
    };



int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&color[i]);
    for(int i = 0;i < n;i++){
        scanf("%d",&d);
        id[0].push_back(d);
        id[color[i]].push_back(d);
    }
    long long ans = 0ll;
    binary_tree<long long> sm(n);
    for(int i = 0;i <= n;i++){
        for(auto it : id[i]){
            if(i == 0)
                ans += sm.query_range(it+1,n);
            else
                ans -= sm.query_range(it+1,n);
            sm.add(it,1ll);
        }
        for(auto it : id[i])
            sm.add(it,-1ll);
    }
    printf("%lld\n",ans);
    return 0;
}