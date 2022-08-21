//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 1e5+10;
const int inf = 1e9;

int a[max_n],b[max_n];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        int l = 1, r = inf,ans = 1;
        while(l <= r){
            int mid = (r+l)/2,cnt = 0;
            for(int i = 1; i <= n; i++){
                b[i] = a[i];
                if(b[i]*2 < mid){
                    cnt++;
                    b[i] = inf;
                }
            }
            int f1=1,f2=1;
            for(int i = 1; i <= n; i++){
                if(b[i] >= mid)
                    f1 = 0;
                if(i < n && std::min(b[i],b[i+1]) >= mid)
                    f2 = 0;
            }
            cnt += f1+f2;
            if(cnt <= k){
                l = mid+1;
                ans = mid;
            }
            else
                r = mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}