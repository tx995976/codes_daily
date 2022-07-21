#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>

const int max_n = 1e3+10;
char str1[max_n],str2[max_n];

int main(){
    scanf("%[^&]&%[^@]@",str1,str2);
    std::string di(str1),de(str2);
    std::reverse(de.begin(),de.end());
    if(di == de)
        printf("%d\n",di.length());
    else
        printf("%s\n","no");
    return 0;
}