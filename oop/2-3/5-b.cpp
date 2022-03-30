#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<unordered_map>
#include<fstream>
#include<vector>
#include<cstring>

struct line_{
    int lin,tra;
    std::string name;
};

std::unordered_map<std::string,int> str_id;//str->id
std::vector<line_> i_line; // <line,trans?>
std::vector<std::vector<int>> edges;

std::vector<std::vector<int>> ans;//
int edge_line[300][300];

int id = 0;

void find_min(int from,int to){
    int max_n = str_id.size();
    std::vector<int>dis(max_n,INT32_MAX),vis(max_n,0);
    ans.resize(max_n);
    dis[from] = 0;
    ans[from].push_back(from);
    //
    for(int i = 0;i < max_n;i++){
        int u = 0, min_now = INT32_MAX;
        for(int j = 0;j < max_n;j++)
            if(!vis[j] && dis[j] < min_now){
                u = j;
                min_now = dis[j]; 
            }
        vis[u] = 1;
        for (auto it : edges[u]){
            int value = 1;
            if(dis[it] > dis[u]+value){
                dis[it] = dis[u]+value;
                ans[it] = ans[u];
                ans[it].push_back(it);
            }
        }
    }
}

void print_way(int to){
    int len = 0,st,ed;
    bool flag = 0;

    st = ans[to][0];
    int line_id = i_line[st].lin;

    printf("%s",i_line[st].name.c_str());

    for(int i = 1;i < ans[to].size();i++){
        int pos = ans[to][i];
        len++;
        if(i_line[pos].tra == 0){
            line_id = i_line[pos].lin;
            continue;
        }
        else
            if(i+1 < ans[to].size())
                if(line_id != i_line[ans[to][i+1]].lin){
                    ed = pos;
                    flag = 1;
                }
        if(i+1 == ans[to].size()){
            ed = pos;
            flag = 1;
        }
        if(flag){
            printf("-%d(%d)-%s",line_id,len,i_line[ed].name.c_str());
            len = 0;
            st = ed;
            flag = 0;
        }
    }
}

int main(){
    std::ifstream in;
    in.open("bgstations.txt",std::ios::in);
    //
    std::string stat,pre;
    int line,n,T,tran;
    in>>T;
    while(T--){
        in>>line>>n;
        for(int i = 1;i <= n;i++){
            in>>stat>>tran;
            //printf("%s %d\n",stat.c_str(),tran);
            if(!str_id.count(stat)){
                str_id[stat] = id++;
                i_line.push_back({line,tran,stat});
                edges.resize(id);
            }
        
            if(i != 1){
                edges[str_id[stat]].push_back(str_id[pre]);
                edges[str_id[pre]].push_back(str_id[stat]);
                edge_line[str_id[stat]][str_id[pre]] = line;
                edge_line[str_id[pre]][str_id[stat]] = line;
            }
            pre = stat;
        }
    }
    //
    in>>stat>>pre;
    //printf("%s %s\n",stat.c_str(),pre.c_str());
    find_min(str_id[stat],str_id[pre]);
    //
    print_way(str_id[pre]);
    //
    return 0;
}