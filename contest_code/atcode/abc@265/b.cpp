//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using ll = long long;

const int max_n = 1e5+10;

int A[max_n],B[max_n];


int main(){
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    for(int i=1;i<=n-1;i++)
        scanf("%d",&A[i]);
    int x;
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        scanf("%d",&B[i]);
    }
    int st = 1;
    bool flag = 0;
    ll T = t;
    while(T > 0){
        T += B[st];
        if(st == n){
            flag = 1;
            break;
        }
        T -= A[st++];
    }
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}