#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 1e5+10;
int a[max_n];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        bool flag = 0;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
            scanf("%d", &a[i]);
        int l = 1,r = n;
        while(l < n && a[l] <= a[l+1])
            l++;    
        while(r > 1 && a[r-1] >= a[r])
            r--;
        printf("%s\n", (l < r) ? "No" : "Yes");
    }
    return 0;
}