//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 4e5+10;

int p[max_n],q[max_n],s[max_n];

int main(){
    int n;
    scanf("%d",&n);
    n *= 2;
    for(int i = 1; i <= n; i++)
        scanf("%d",&p[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d",&q[i]);

    auto ext = [&](){printf("-1\n");return 0;};

    for(int i = 1; i <= n; i += 2){
        if(p[i] > p[i+1]){
            if(i > 1 && (p[i] < p[i-2] || p[i+1] < p[i-1]) )
                ext();
            s[p[i]] = 1;
            s[p[i+1]] = -1;
        }
    }
    for(int i = 1; i <= n; i += 2){
        if(q[i] < q[i+1]){
            if((i > 1 && (q[i] > q[i-2] || q[i+1] > q[i-1])) || s[q[i]] || s[q[i+1]])
                ext();
            s[q[i]] = 1;
            s[q[i+1]] = -1;
        }
    }

    for(int i = 1; i <= n;i++)
         if(!s[i])
            ext();
    for(int i = 1; i <= n;i++)
        printf("%c",s[i] == 1 ? '(' : ')');
    return 0;
}