//#
//@分治
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

int judge(std::vector<int> &p){
    printf("? %d %d\n",p[0],p[2]); fflush(stdout);
    int res;
    scanf("%d",&res);
    if(res == 1){
        printf("? %d %d\n",p[0],p[3]); fflush(stdout);
        scanf("%d",&res);
        if(res == 1)
            return p[0];
        return p[3];
    }
    else if(res == 2){
        printf("? %d %d\n",p[1],p[2]); fflush(stdout);
        scanf("%d",&res);
        if(res == 1)
            return p[1];
        return p[2];
    }
    else{
        printf("? %d %d\n",p[1],p[3]); fflush(stdout);
        scanf("%d",&res);
        if(res == 1)
            return p[1];
        return p[3];
    }
    return 0;
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        std::vector<int> par,cp;
        for(int i = 1;i <= (1ll<<n);i++)
            par.emplace_back(i);
        while(par.size() > 2){
            while(!par.empty()){
                std::vector<int> group(4);
                group[0] = par.back();
                par.pop_back();
                group[1] = par.back();
                par.pop_back();
                group[2] = par.back();
                par.pop_back();
                group[3] = par.back();
                par.pop_back();
                int wp = judge(group);
                cp.emplace_back(wp);
            }
            par = cp;
            cp.clear();
        }
        if(par.size() == 2){
            int res;
            printf("? %d %d\n",par[0],par[1]); fflush(stdout);
            scanf("%d",&res);
            if(res == 2)
                par[0] = par[1];
        }
        printf("! %d\n",par[0]); fflush(stdout);
    }
    return 0;
}