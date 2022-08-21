//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 5e2+10;
int arr[max_n][max_n];


int main(){
    int n,s = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i += 2)
        for(int j = 1;j<=n;j++)
            arr[i][j] = s++;
    for(int i=2;i<=n;i += 2)
        for(int j = 1;j<=n;j++)
            arr[i][j] = s++;

    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

    return 0;
}