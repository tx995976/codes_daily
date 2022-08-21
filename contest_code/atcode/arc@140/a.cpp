//#
//@
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

std::string str;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    std::cin>>str;
    int div = 1;
    for(;div <= n;div++){
        if(n % div != 0)
            continue;
        int ned = 0;
        for(int j = 0;j < div;j++){
            std::vector<int> cnt(26,0);
            for(int l = j;l < n;l += div)
                cnt[str[l]-'a'] += 1;
            ned += (n/div - *std::max_element(cnt.begin(),cnt.end()));
        }
        if(ned <= k){
            printf("%d\n",div);
            return 0;
        }
    }    

    return 0;
}