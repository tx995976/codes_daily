#include <iostream>
#include<vector>

#pragma once

namespace my_graph{
    const int max_n = 1e2+10;

    
    struct Arcinfo{
       std::string from,to;
       int weight;
    };

    struct ArcNode{
        int adjvex,weight;
        ArcNode *next_arc;
    };

    
    struct Vnode{
        std::string  data;
        int in;
        ArcNode *fir_arc;
    };


    class AL_graph{
        public:
            int num_vex;
            int num_arc;
            std::vector<Vnode> vertices;

        public:
            ~AL_graph(){}
            AL_graph(){}

            void create_graph(Arcinfo aeclist[]);
            void in_degree();
            void display();
            void top_order();

    };

    
}