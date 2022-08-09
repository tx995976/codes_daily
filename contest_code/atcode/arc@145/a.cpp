#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<iostream>

std::string str;

int main(){
    int n;
    scanf("%d",&n);
    std::cin>>str;

    if(n == 2){
        printf("%s\n",str[0] == str[n-1] ? "Yes" : "No");
    }
    else{
        if((str[0] == 'A' && str[n-1] == 'A') || str[0] == 'B')
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}