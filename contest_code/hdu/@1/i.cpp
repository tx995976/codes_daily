//#几何
//
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 5e5+10;

int x[max_n],y[max_n],xa[max_n],ya[max_n];
int t,n;

bool check_line(int xi,int yi){
    for(int i = 1;i <= n;i++){
        if(xi == x[i] || yi == y[i] || xi-x[i] == yi-y[i] || xi+yi == x[i]+y[i])
            continue;
        else
          return 0;
    }
    return 1;
}

bool check(){
    bool flag = 1;
    for(int i = 2;i <= n;i++){
        if(x[i] == x[1])
            continue;
        flag = 0;
        if(check_line(x[1],y[i]))
            return 1;
        if(check_line(x[1],y[i] + (x[i]-x[1])))
            return 1;
        if(check_line(x[1],y[i] - (x[i]-x[1])))
            return 1;
        break;
    }
    if(flag)
        return 1;
    return 0;
}

int main(){
    scanf("%d",&t);
    while(t--){
        bool flag = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d %d",&xa[i],&ya[i]);
        for(int i = 1;i <= n;i++)
            x[i] = xa[i],y[i] = ya[i];
        flag = check();
        if(!flag){
            for(int i = 1;i <= n;i++)
                x[i] = ya[i],y[i] = xa[i];
            flag = check();
        }
        if(!flag){
            for(int i = 1;i <= n;i++)
                x[i] = xa[i] + ya[i],y[i] = xa[i] - ya[i];
            flag = check();
        }
        if(!flag){
            for(int i = 1;i <= n;i++)
                x[i] = xa[i] - ya[i],y[i] = xa[i] + ya[i];
            flag = check();
        }
        printf("%s\n",flag ? "YES" : "NO");
    }
    return 0;
}