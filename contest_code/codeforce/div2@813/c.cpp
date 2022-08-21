//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 1e5+10;
int arr[max_n];

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        std::vector<int> mark[n+1]; 
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            mark[arr[i]].push_back(i);
        }
        int l = 1,ans = 0;
        for(int i = 2;i<=n;i++){
            if(arr[i-1] > arr[i]){
                for(int j = l;j < i;j++){
                    if(arr[j] == 0)
                        continue;
                    ans += 1;
                    for(int it : mark[arr[j]])
                        arr[it] = 0;
                }
                l = i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}