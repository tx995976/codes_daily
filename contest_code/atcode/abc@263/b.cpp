#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

int pat[51];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 2;i <= n;i++)
        scanf("%d",&pat[i]);
    int ans = 1,st = n;
    while(pat[st] != 1){
        st = pat[st];
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}