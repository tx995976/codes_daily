//#计数
//
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 5e5+10;

template<class T>
    class binary_tree{
        int max_tree;
        std::vector<T> tree;
    public:
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

int nums[max_n],swp[max_n];


int main(){
    int n;
    long long ans = 0ll;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf(" %d",&nums[i]);
    binary_tree<int> tree(max_n);
    for(int i = 1;i <= n;i++){
        if(nums[i] == i){
            ans += tree.query(nums[i]-1);
            tree.add(nums[i],1);
        }
        else if(!swp[i]){
            if(nums[nums[i]] == i){
                ans += 1;
                swp[i] = swp[nums[i]] = 1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}