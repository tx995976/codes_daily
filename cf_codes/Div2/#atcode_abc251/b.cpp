#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 1e6+10;
int N,W,A[max_n];
bool num[max_n];
int ans;

int main(){
    scanf("%d %d",&N,&W);
    for(int i=1;i <= N;i++){
        scanf("%d",&A[i]);
        if(A[i] <= W)
            num[A[i]] = true;
    }

    for(int i = 1;i <= N;i++)
        for(int k = i+1; k <= N;k++){
            if(A[i] + A[k] <= W) 
                num[A[i] + A[k]] = true;
            for(int j = k+1; j <= N;j++){
                if(A[i] + A[k] + A[j] <= W) 
                    num[A[i] + A[k] + A[j]] = true;
            }
        }

    for(int i = 1;i <= W ;i++)
        if(num[i])
            ans++;
    printf("%d\n",ans);
    return 0;
}