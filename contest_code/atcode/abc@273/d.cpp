//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>

// H = row W = column
int H,W,rs,cs,N,Q;
std::map<int,std::set<int>> wall_H,wall_W;

int main(){
    scanf(" %d %d %d %d %d",&H,&W,&rs,&cs,&N);
    int ri,ci;
    for(int i=0;i<N;i++){
        scanf(" %d %d",&ri,&ci);
        wall_H[ri].insert(ci);
        wall_W[ci].insert(ri);
    }

    scanf(" %d",&Q);
    char d;
    int l;
    for(int i = 0;i<Q;i++){
        scanf(" %c %d",&d,&l);
        int limit;
        switch(d){
            case 'R':{
                auto it = wall_H[rs].upper_bound(cs);
                limit = (it == wall_H[rs].end()) ? W+1 : *it;
                cs = ((cs+l) >= limit ? limit-1 : (cs+l)); 
                break;
            }
            case 'L':{
                auto it = wall_H[rs].lower_bound(cs);
                limit = (it == wall_H[rs].begin()) ? 0 : *(--it);
                cs = ((cs-l) <= limit ? limit+1 : (cs-l)); 
                break;
            }
            case 'U':{
                auto it = wall_W[cs].lower_bound(rs);
                limit = (it == wall_W[cs].begin()) ? 0 : *(--it);
                rs = ((rs-l) <= limit ? limit+1 : (rs-l));
                break;
            }
            case 'D':{
                auto it = wall_W[cs].upper_bound(rs);
                limit = (it == wall_W[cs].end()) ? H+1 : *it;
                rs = ((rs+l) >= limit ? limit-1 : (rs+l));
                break;
            }
        }
        printf("%d %d\n",rs,cs);
    }
    return 0;
}