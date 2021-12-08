#include <iostream>
#include<vector>
#include<algorithm>

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
        ArcNode(){}
        ArcNode(int a,int b){adjvex = a;weight = b;}
    };

    
    struct Vnode{
        std::string  data;
        int in = 0;
        ArcNode *fir_arc;
    };
    bool cmp_in(const Vnode &l,const Vnode &r){
        return l.in < r.in;
    }


    class AL_graph{
        public:
            int num_vex;
            int num_arc;
            int all_weight;
            std::vector<Vnode> vertices;
            std::vector<Arcinfo> infos;

        public:
            ~AL_graph(){}
            AL_graph(){}

            void create_graph();
            void graph_ready();
            void display();
            void top_order();
            
            bool new_VNode(Vnode &a);
            bool new_ArcInfo(Arcinfo &a);
            bool delete_VNode(std::string &a);
            bool delete_ArcInfo(Arcinfo &a);
            
            int find_node(std::string &a);
    };
    
    bool AL_graph::new_VNode(Vnode &a){
        for(auto it : vertices){
            if(it.data ==a.data)
                return 0;
        }
        vertices.push_back(a);
        num_vex++;
        return 1;
    }

    bool AL_graph::new_ArcInfo(Arcinfo &a){
        for(auto it : infos){
            if(it.from == a.from && it.to == a.to){
                it.weight = a.weight;
                return 0;
            }
        }
        infos.push_back(a);
        num_arc++;
        return 1;
    }

    int AL_graph::find_node(std::string &a){
        int i = 0;
        for(auto it : vertices){
            if(it.data == a)
                return  i;
            i++;
        }
        return num_vex;
    }
////////////////////////////////////////////
    void AL_graph::graph_ready(){
        for(auto it : infos){
            all_weight += it.weight;
            vertices[find_node(it.to)].in += 1;
            ArcNode *from = vertices[find_node(it.from)].fir_arc;
            while(from != nullptr)
                from = from->next_arc;
            *from = ArcNode(find_node(it.to),it.weight);
        }
    }

    void AL_graph::top_order(){
        std::vector<Vnode> U;
        std::sort(vertices.begin(),vertices.end(),cmp_in);
        int non_flag = 1;

        while(U.size() < num_vex && non_flag){
            for(auto it : vertices){
                if(it.in == 0){
                    auto i = it.fir_arc;
                    while(i != nullptr){
                        vertices[i->adjvex].in -= 1;
                        i = i->next_arc;
                    }
                    U.push_back(it);
                    it.in = -1;
                    non_flag = 1;
                    break;
                }
                non_flag = 0;
            }
        }



        return;
    }
        

    void AL_graph::display(){
       
    }

}
