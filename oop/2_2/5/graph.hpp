#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include<vector>

#pragma once

namespace my_graph{
    const int max_n = 20;

    struct Vex{
        int code;
        std::string name;
        Vex(){}
        Vex(int a,std::string b){code = a,name = b;}
        bool operator == (const Vex &r){
            return code == r.code && name == r.name;
        }
    };
    bool update_judge(const Vex &a,const Vex &b){
        return a.code == b.code;
    }

    struct Edge{
        Vex vex1,vex2;
        int length;
        Edge(){}
        Edge(Vex a, Vex b,int c){vex1 = a,vex2 = b;length = c;}
    };
    bool update_judge_1(const Edge &a,const Edge &b){
        return a.vex1 == b.vex1 && a.vex2 == b.vex2;
    }

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

            Edge get_edge(std::string vex_code1,std::string vex_code2);
            Vex get_vex(std::string vex_code);
            
            int print_prim();
            int print_kruskal();
    };

    bool non_dgraph::insert_vex(Vex svex){
        vexs.push_back(svex);
        num_vex++;
        return 1;
    }

    bool non_dgraph::insert_edge(Edge sedge){
        edges.push_back(sedge);
      // int c_a = sedge.vex1.code,c_b = sedge.vex2.code;
       // adj_matrix[c_a][c_b] = sedge.length;
        //adj_matrix[c_b][c_a] = sedge.length;
        return 1;
    }

    bool non_dgraph::delete_vex(Vex svex){
        auto i = std::find(vexs.begin(),vexs.end(),svex);
        if(i == vexs.end()){
            return false;
        }
        else
            vexs.erase(i);
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
        auto equal = std::bind(update_judge,svex,std::placeholders::_1);
        auto i = std::find(vexs.begin(),vexs.end(),equal);
        if(i == vexs.end())
            return 0;
        else
            *i = svex;
        return true;
    }

    bool non_dgraph::update_edge(Edge sedge){
        auto equal = std::bind(update_judge_1,sedge,std::placeholders::_1);
        auto i = std::find(edges.begin(),edges.end(),equal);
        if(i == edges.end())
            return 0;
        else
            *i = sedge;
        return 1;
    }

}
