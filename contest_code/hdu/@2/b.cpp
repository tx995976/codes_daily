#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

std::string str;

int main(){
    int t;
    char temp;
    scanf("%d",&t);
    while(t--){
        str.clear();
        scanf("\n");
        while((temp = getchar()) != '\n'){
            if(temp == '(' || temp == ')' || temp == '-' || temp == ',' ||std::isdigit(temp))
                str.push_back(temp);
        }
        printf("%s\n",str.c_str());
    }
    return 0;
}