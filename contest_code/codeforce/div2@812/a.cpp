#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int max_x = 0,max_y = 0,min_x = 0,min_y = 0;
        int x,y,n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d %d",&x,&y);
            max_x = std::max(max_x,x);
            min_x = std::min(min_x,x);
            max_y = std::max(max_y,y);
            min_y = std::min(min_y,y);
        }
        printf("%d\n",2*(max_x+max_y-min_x-min_y));
    }
    return 0;
}