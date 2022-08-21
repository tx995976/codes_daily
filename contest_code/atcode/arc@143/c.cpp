//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 2e5+10;

int main(){
    int n,x,y;
    scanf("%d %d %d", &n,&x,&y);
    std::vector<int> arr(n+1);
    bool flag = 0,win = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        arr[i] %= x+y;
        if(arr[i] >= x)
            flag = 1;
        if(x > y && arr[i] < x && arr[i] >= y){
            win = 1;
            break;
        }
    }
    if(!flag && !win)
        win = 1;
    printf("%s\n",win ? "Second" : "First");
    return 0;
}