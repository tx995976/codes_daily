//#图论/网络流
//@最大流
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<queue>

using ll = long long;
const int max_p = 2e7+10;
const int inf = 1e9;

struct prime{
    std::vector<bool> flag_prime;
    void prime_list(int range){
        flag_prime.resize(range+1,1);
        flag_prime[1]=0 ;
        for(int i = 2;i <= range;i++){
            if(!flag_prime[i])
                continue;
            for(int j=i+i;j <= range;j+=i)
                flag_prime[j]=0;
        }
    }
};
struct max_flow{
    int n;
    ll max_T;
    struct eg{
        int to;
        ll val;
    };

    std::vector<eg> ed;
    std::vector<std::vector<int>> gh;
    std::vector<int> cur,h;
    max_flow(int in){
        n = in;
        max_T = std::numeric_limits<ll>::max();
        gh.resize(in);
    }

    void add_edge(int f,int t,ll val){
        gh[f].push_back(ed.size());
        ed.push_back((eg){t,val});
        gh[t].push_back(ed.size());
        ed.push_back((eg){f,0});
    }

    bool bfs(int s,int t){
        h.assign(n,-1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while(!que.empty()){
            int i = que.front();
            que.pop();
            for(int it : gh[i]){
                auto [v,c] = ed[it]; 
                if(c > 0 && h[v] == -1){
                    h[v] = h[i] + 1;
                    if(v == t)
                        return 1;
                    que.push(v);
                }
            }
        }
        return 0;
    }

    ll dfs(int u,int t,ll val){
        if(u == t)
            return val;
        auto r = val;
        for(int &i = cur[u];i < (int)gh[u].size();i++){
            const int j = gh[u][i];
            auto [v,c] = ed[j];
            if(c > 0 && h[v] == h[u] + 1 ){
                auto a = dfs(v,t,std::min(r,c));
                r -= a;
                ed[j].val -= a;
                ed[j^1].val += a;
                if(r == 0)
                    return val;
            }
        }
        return val - r;
    }

    ll mflow(int s,int t){
        ll ans = 0;
        while(bfs(s,t)){
            cur.assign(n,0);
            ans += dfs(s,t,INT64_MAX);
        }
        return ans;
    }
};

std::vector<int> od,c_od,ev,c_ev;

int main(){
    int n;
    prime pr;
    pr.prime_list(max_p);

    scanf("%d", &n);
    std::vector<int> a(n),b(n);
    int c_1 = 0;
    for(int i = 0;i < n;i++){
        scanf("%d %d", &a[i],&b[i]);    
        if(a[i] == 1){
            c_1 = b[i];
            b[i] = 0;
        }
    }
    
    max_flow fm(n+3);
    for(int i = 0;i < n;i++){
        if(a[i] % 2 == 0){
            fm.add_edge(n,i,b[i]);
            for(int j = 0;j < n;j++)
                if(a[j] % 2 == 1 && pr.flag_prime[a[i]+a[j]])
                    fm.add_edge(i,j,inf);
        }
        else
            fm.add_edge(i,n+1,b[i]);
    }
   
    ll L = fm.mflow(n,n+1);
    fm.add_edge(n+2,n+1,c_1);
    for(int i = 0;i < n;i++)
        if(a[i] % 2 == 0 && pr.flag_prime[a[i]+1])
            fm.add_edge(i,n+2,inf);
   
    ll R = L + fm.mflow(n,n+1);

    ll ans = R + (c_1 - (R - L)) / 2;
    printf("%lld\n",ans);
    return 0;
}