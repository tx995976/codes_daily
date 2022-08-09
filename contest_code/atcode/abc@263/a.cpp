#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

int cnt[14];

int main(){
    int a,b,c,d,e;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    cnt[a] += 1;
    cnt[b] += 1;
    cnt[c] += 1;
    cnt[d] += 1;
    cnt[e] += 1;
    bool c2 = 0, c3 = 0;
    for(int i = 1;i <= 13;i++){
        if(cnt[i] == 3)
            c3 = 1;
        if(cnt[i] == 2)
            c2 = 1;
    }
    printf("%s\n",c2 && c3 ? "Yes" : "No");
    return 0;
}