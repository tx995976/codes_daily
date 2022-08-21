#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

const int max_n = 1e5+10;

int n,ans[max_n];

void f(int r){
    if(r < 0)
        return;
    int s = std::sqrt(2*r);
    s = s*s;
    int l = s - r;
    f(l-1);
    for(;l <= r;l++,r--){
        ans[l] = r;
        ans[r] = l;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        f(n-1);
        for(int i=0;i<n;i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}