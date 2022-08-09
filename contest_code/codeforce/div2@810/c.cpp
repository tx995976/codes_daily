//#
//@思维
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
const int max_n = 1e5+10;
int ai[max_n];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for(int i = 1; i <= k; i++)
            scanf("%d",&ai[i]);

        ll ev = 0ll;
        bool flag = 0,ans = 0;

        // m 
        for(int i = 1; i <= k; i++){
            int num = ai[i]/m;
            if(num >= 2)
                ev += num;
            if(num > 2)
                flag = 1;
        }
        if(ev >= n && (flag || n%2 == 0))
            ans = 1;
            
        if(!ans){
            flag = 0;
            ev = 0ll;
            // n 
            for(int i = 1; i <= k; i++){
                int num = ai[i]/n;
                if(num >= 2)
                    ev += num;
                if(num > 2)
                    flag = 1;
            }
            if(ev >= m && (flag || m%2 == 0))
                ans = 1;
        }
        printf("%s\n",ans ? "Yes" : "No");
    }
    return 0;
}