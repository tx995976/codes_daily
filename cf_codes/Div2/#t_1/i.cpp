#include <iostream>

const int max_n = 1e6+10;
int n,m,ans_min = 0,ans_max = 0,t_in,money[max_n],mid,ans;

bool check(int mid){
    int n=1 ,plus = 0;
    for(int i = 1;i <= m;i++){
        if(plus+money[i] > mid){
            plus = money[i];
            n++;
        }
        else
            plus += money[i];
    }
    return n <= ::n;
}

void solve(){
    while(ans_min <= ans_max){
        mid = (ans_min + ans_max)>>1;
        if(check(mid)){
            ans_max = mid - 1;
            ans = mid;
        }
        else
            ans_min = mid + 1;
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i = 1;i <= m;i++){
        scanf("%d",&t_in);
        money[i] = t_in;
        ans_min = std::max(ans_min,t_in);
        ans_max += t_in;
    }
    solve();
    return 0;
}
