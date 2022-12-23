//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

std::map<int,int> cnt_num;

int main(){
    int n,d;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        cnt_num[d] += 1;
    }

    int num = 0;
    for(auto it = cnt_num.crbegin();it != cnt_num.crend();it++){
        printf("%d\n",it->second);
        num++;
    }
    for(int i = num;i < n;i++){
        printf("0\n");
    }
    return 0;
}