//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>

int N,Q;
std::unordered_map<int,std::set<int> > map_follow;

int main(){
    scanf("%d %d",&N,&Q);    
    int t,a,b;
    while(Q--){
        scanf("%d %d %d",&t,&a,&b);
        switch(t){
            case 1:
                map_follow[a].insert(b);
                break;
            case 2:
                map_follow[a].erase(b);
                break;
            case 3:
                printf("%s\n",(map_follow[a].count(b) && map_follow[b].count(a)) ? "Yes" : "No");
                break;
        }
    }
    return 0;
}