#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>


int main(){
    int l1,r1,l2,r2;
    int ans = 0;
    scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
    if(l1 < r2 && l1 >= l2)
        ans = std::min(r1,r2) - l1;
    else if(l2 < r1 && l2 >= l1)
        ans = std::min(r2,r1) - l2;
    printf("%d\n",ans);
    return 0;
}