#include <iostream>
#include<vector>

#pragma once

namespace my_graph{
    const int max_n = 20;

    struct Vex{
        std::string code,name;
    };
    
    struct Edge{
        Vex vex1,vex2;
        int length;
    };


    template<class T>
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

            Edge get_edge(std::string vex_code1,std::string vex_code2);
            Vex get_vex(std::string vex_code);
            
            int print_prim();
            int print_kruskal();
    };



}
