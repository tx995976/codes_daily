//#博弈 
//
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 1e6+10;
int num[max_n];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 0; i <= n; i++)
            scanf("%d",&num[i]);
        for(int i = n; i > 0; i--)
            num[i-1] += num[i]/2;
        if(num[0])
            printf("Alice\n");
        else 
            printf("Bob\n");
    }
    return 0;
}