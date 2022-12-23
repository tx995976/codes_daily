//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>


int main(){
    int x,y,n;
    scanf("%d %d %d",&x,&y,&n);
    int ans = 0;
    if(n < 3)
        ans += x*n;
    else{
        while(n >= 3){
            if(x*3 >= y){
                ans += y;
                n -= 3;
            }
            else{
                ans += 3*x;
                n -= 3;
            }
        }
        if(n)
            ans += x*n;
    }
    printf("%d\n",ans);
    return 0;
}