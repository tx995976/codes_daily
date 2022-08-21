//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

char str[] = "atcoder";

int main(){
    int l,r;
    scanf("%d %d",&l,&r);
    printf("%.*s\n",r-l+1,str+(l-1));
    return 0;
}