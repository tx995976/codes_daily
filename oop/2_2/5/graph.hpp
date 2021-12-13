#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include<vector>
#include<functional>


#pragma once

namespace my_graph{
    const int max_n = 20;

    struct Vex{
        int code;
        std::string name;
        Vex(){}
        Vex(int a,std::string b){code = a,name = b;}
        bool operator== (const Vex &r)const{
            return code == r.code && name == r.name;
        }
    };
    //
    bool update_judge(const Vex &a,const Vex &b){
        return a.code == b.code;
    }

    struct Edge{
        Vex vex1,vex2;
        int length;
        Edge(){}
        Edge(Vex a, Vex b,int c){vex1 = a,vex2 = b;length = c;}
        bool operator== (const Edge &r)const{
            return vex1 == r.vex1 && vex2 == r.vex2 && length == r.length ;
        }
        bool operator< (const Edge &r)const{
            return length < r.length;
        }
    };
    //
    bool update_judge_1(const Edge &a,const Edge &b){
        return a.vex1 == b.vex1 && a.vex2 == b.vex2
            || a.vex1 == b.vex2 && a.vex2 == b.vex1;
    }

    struct my_union{
        int father[max_n];
        int find(int x){
            if(x != father[x])
                father[x] = find(father[x]);
            return father[x];
        }
        void unionset(int a,int b){
            a = find(a);
            b = find(b);
            father[a] = b;
        }
    };

    class non_dgraph{
        private:
            int adj_matrix[max_n][max_n];
            std::vector<Vex> vexs;
            std::vector<Edge> edges;
            int num_vex;
        public:
            non_dgraph(){}
            ~non_dgraph(){}

            bool insert_vex(Vex svex);
            bool delete_vex(Vex svex);
            bool update_vex(Vex svex);
            bool insert_edge(Edge sedge);
            bool delete_edge(Edge sedge);
            bool update_edge(Edge sedge);
            
            bool graph_ready();

            Edge get_edge(int vex_code1,int vex_code2);
            Vex get_vex(int vex_code);
            
            int print_prim();
            int print_kruskal();
            void show_TE(std::vector<Edge> &TE);
    };

    bool non_dgraph::insert_vex(Vex svex){
        auto i = std::find(vexs.begin(),vexs.end(),svex);
        if(i != vexs.end()){
            return false;
        }
        vexs.push_back(svex);
        num_vex++;
        return 1;
    }

    bool non_dgraph::insert_edge(Edge sedge){
        auto i =std::find(edges.begin(),edges.end(),sedge);
        if(i != edges.end())
            return false;
        edges.push_back(sedge);
        return 1;
    }

    bool non_dgraph::delete_vex(Vex svex){
        auto i = std::find(vexs.begin(),vexs.end(),svex);
        if(i == vexs.end()){
            return false;
        }
        else
            vexs.erase(i);
            num_vex--;
        return true;
    }
    
    bool non_dgraph::delete_edge(Edge sedge){
        auto i =std::find(edges.begin(),edges.end(),sedge);
        if(i == edges.end())
            return false;
        else
            edges.erase(i);
        return true;
    }

    bool non_dgraph::update_vex(Vex svex){
        auto it = vexs.begin();
        while(it != vexs.end()){
            if(update_judge(svex,*it)){
                *it = svex;
                return 1;
            }
            it++;
        }
        return 0;
    }

    bool non_dgraph::update_edge(Edge sedge){
        auto it = edges.begin();
        while(it != edges.end()){
            if(update_judge_1(*it,sedge)){
                *it = sedge;
                return 1;
            }
            it++;
        }
        return 0;
    }

    bool non_dgraph::graph_ready(){
        for(auto it : edges){
            adj_matrix[it.vex1.code][it.vex2.code] = it.length;
            adj_matrix[it.vex2.code][it.vex1.code] = it.length;
        }
        return 1;
    }
    ///?
    Edge non_dgraph::get_edge(int vex_code1,int vex_code2){
            for(auto i : edges)
                if(i.vex1.code == vex_code1 && i.vex2.code == vex_code2
                || i.vex1.code == vex_code2 && i.vex2.code == vex_code1){
                    return i;
                }
            return edges.back();
    }
    ///?
    Vex non_dgraph::get_vex(int vex_code){
        for(auto i : vexs)
            if(i.code == vex_code)
                return i;
        return vexs.back();
    }
    
/////////////////////////////////////////////
    int non_dgraph::print_prim(){
        this->graph_ready();
        int code_now,code,min_value = INT32_MAX;
        std::vector<Vex> U;
        std::vector<Edge> TE;
        U.push_back(vexs.front());
        while(U.size() < vexs.size()){
            for(auto it : U){
                for(int i = 1;i <= max_n;i++){
                    if(adj_matrix[it.code][i])
                        if(adj_matrix[it.code][i] < min_value){
                            min_value = adj_matrix[it.code][i];
                            code = i;
                            code_now = it.code;
                            adj_matrix[it.code][i] = 0;
                            adj_matrix[i][it.code] = 0;
                        }
                }
            }
            U.push_back(get_vex(code));
            TE.push_back(get_edge(code,code_now));
            min_value = INT32_MAX;
        }
        show_TE(TE);
        return 1;
    }

    int non_dgraph::print_kruskal(){
        this->graph_ready();
        int code_now,code,min_value;
        std::vector<Vex> U(vexs);
        std::vector<Edge> TE;
        my_union gra_union;

        std::sort(edges.begin(),edges.end());
        for(auto it : edges){
            int ve_1 = it.vex1.code , ve_2 = it.vex2.code;
            if(!gra_union.father[ve_1] && !gra_union.father[ve_2]){
                gra_union.father[ve_1] = ve_1;
                gra_union.father[ve_2] = ve_1;
            }
            else if(!gra_union.father[ve_1] && gra_union.father[ve_2])
                gra_union.father[ve_1] = gra_union.father[ve_2];
            else if(gra_union.father[ve_1] && !gra_union.father[ve_2])
                gra_union.father[ve_2] = gra_union.father[ve_1];
            else if(gra_union.find(ve_1) == gra_union.find(ve_2))
                continue;
            else{
                gra_union.unionset(ve_1,ve_2);
            }
            TE.push_back(it);
        }
        show_TE(TE);
        return 1;
    }

    void non_dgraph::show_TE(std::vector<Edge> &TE){
        for(auto it : TE){
            printf("%d:%s %d:%s length:%d\n",
                it.vex1.code,
                it.vex1.name.c_str(),
                it.vex2.code,
                it.vex2.name.c_str(),
                it.length
            );
        }
    }
    
}