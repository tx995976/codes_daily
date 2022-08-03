#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>


int main(){
    int i;
    scanf("%d",&i);
    if(i % 4 != 2){
        int cnt = i / 4 + (i%4 > 2 ? 1 : 0);
        i = cnt * 4 + 2;
    }
    printf("%d\n",i);
    return 0;
}