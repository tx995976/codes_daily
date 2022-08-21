//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>


int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    std::vector<int> arr(n-1);
    int m = n/2,d = 1;
    if(n%2 == 0 && x == n/2)
        d = -1;
    for(int i = 0;i < n-1;i++){
        arr[i] = m;
        m += d;
        if(d > 0)
            d += 1;
        else
            d -= 1;
        d *= -1;
    }
    printf("%d ",x);
    for(int i : arr)
        printf("%d ",i < x ? i : i+1);
    return 0;

}