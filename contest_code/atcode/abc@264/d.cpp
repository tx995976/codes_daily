//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

template<typename T>
   struct binary_tree{
        int max_tree;
        std::vector<T> tree;
        binary_tree(int n){
            max_tree = n;
            tree.resize(n+1);
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

int mp['z'];

int main(){
    mp['a'] = 1,mp['t'] = 2,mp['c'] = 3,mp['o'] = 4,mp['d'] = 5,mp['e'] = 6,mp['r'] = 7;
    int i = 7,ans = 0;
    binary_tree<int> par(8);
    while(i--){
        char c;
        scanf("%c",&c);
        int t = mp[(int)c];
        par.add(t,1);
        ans += par.query_range(t+1,par.max_tree);
    }
    printf("%d\n",ans);
    return 0;
}