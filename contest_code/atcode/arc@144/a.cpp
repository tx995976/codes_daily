#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

std::string num;

int main(){
    int n;
    scanf("%d",&n);
    int cnt = n / 4,mod = n % 4;
    if(mod != 0)
        num.push_back('0'+mod);
    if(cnt != 0)
        num.insert(num.end(),cnt,'4');
    printf("%d\n%s\n",n*2,num.c_str());
    return 0;
}