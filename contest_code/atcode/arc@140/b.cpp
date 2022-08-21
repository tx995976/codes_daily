//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 2e5+10;

char str[max_n];
int cnt_r[max_n];


int main(){
    int n;
    scanf("%d", &n);
    scanf(" %s",&str);

    for(int i=0;i<n;i++){
        if(str[i] != 'R')
            continue;
        int a = i,c = i;
        while(a-1 >= 0 && c+1 < n){
            if(str[a-1] == 'A' && str[c+1] == 'C')
                a--,c++;
            else
                break;            
        }
        cnt_r[std::min(i-a,c-i)] += 1;
    }

    int l = 1,r = n,ans = 0;
    while(l <= r){
        while(!cnt_r[r] && r > 0)
            r--;
        if(r <= 0)
            break;
        cnt_r[r] -= 1;
        cnt_r[r-1] += 1;
        ans += 1;

        if(r == l && l > 1)
            l -= 1;

        while(!cnt_r[l] && l < n)
            l++;
        if(l >= n)
            break;
        cnt_r[l] -= 1;
        ans += 1;
    }
    printf("%d\n",ans);
    return 0;
}