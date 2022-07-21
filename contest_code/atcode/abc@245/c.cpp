#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>

const int max_n = 2e5+10;
int K,N;
int A[max_n],B[max_n];
bool dp_a[max_n],dp_b[max_n];
bool flag = 0;

int main(){
    scanf(" %d %d",&N,&K);
    for(int i = 1;i <= N;i++)
        scanf(" %d",&A[i]);
    for(int i = 1;i <= N;i++)
        scanf(" %d",&B[i]);
    dp_a[1] = dp_b[1] = 1;
    for(int i = 2;i <= N;i++){
        if(dp_a[i-1]){
            if(std::abs(A[i-1]-A[i]) <= K)
                dp_a[i] = 1;
            if(std::abs(A[i-1]-B[i]) <= K)
                dp_b[i] = 1;
        }
        if(dp_b[i-1]){
            if(std::abs(B[i-1]-A[i]) <= K)
                dp_a[i] = 1;
            if(std::abs(B[i-1]-B[i]) <= K)
                dp_b[i] = 1;
        }
    }
    printf("%s\n",(dp_a[N]||dp_b[N]) ? "Yes" : "No");
    return 0;
}
