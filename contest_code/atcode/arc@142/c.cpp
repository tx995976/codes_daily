//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

int c1[3],cnt1=0;

int ask(int p){
    int d1,d2;
    printf("? 1 %d\n", p); fflush(stdout);
    scanf("%d", &d1);
    printf("? 2 %d\n", p); fflush(stdout);
    scanf("%d", &d2);
    if(d1+d2 == 3)
        c1[++cnt1] = p;
    return d1+d2;
}

int ask(int c,int d){
    int res;
    printf("? %d %d\n",c,d); fflush(stdout);
    scanf("%d", &res);
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    int ans = INT32_MAX;
    for(int i=3;i <= n;i++)
        ans = std::min(ans,ask(i));

    if(cnt1 == 1 && ans == 3)
        ans = 1;
    else if(cnt1 == 2 && ans == 3){
        int as = ask(c1[1],c1[2]);
        if(as == 2 || as == 3)
            ans = 1;
        else
            ans = 3;
    }
    printf("! %d\n", ans);fflush(stdout);
    return 0;
}