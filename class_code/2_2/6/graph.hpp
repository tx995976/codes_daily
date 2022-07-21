#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<numeric>

#pragma once

namespace my_graph{
    const int max_n = 1e2+10;

    struct info_class{
        int number;
        std::string name;
        double scope;
        info_class(){}
        info_class(int c,std::string a,double b){
            number = c;
            name = a;
            scope = b;
        }
        bool operator== (const info_class &r)const{
            return number == r.number && name == r.name && scope == r.scope;
        }
    };


    struct Arcinfo{
       std::string from,to;
       int weight;
       bool operator== (const Arcinfo &r)const{
           return from == r.from && to == r.to && weight == r.weight;
       }
    };

    struct ArcNode{
        int adjvex,weight;
        ArcNode *next_arc = nullptr;
        ArcNode(){}
        ArcNode(int a,int b){adjvex = a;weight = b;next_arc = nullptr;}
    };

    
    struct Vnode{
        info_class  data;
        int in = 0;
        ArcNode *fir_arc;
        bool operator== (const Vnode &r)const{
            return data == r.data;
        }
        bool operator< (const Vnode &r)const{
            return data.scope < r.data.scope;
        }
    };
    bool cmp_in(const Vnode &l,const Vnode &r){
        return l.in < r.in;
    }


    class AL_graph{
        public:
            int num_vex;
            int num_arc;
            double all_weight;
            std::vector<Vnode> vertices;
            std::vector<Arcinfo> infos;
            std::vector<Vnode> result;

        public:
            ~AL_graph(){}
            AL_graph(){}

            void create_graph();
            void graph_ready();
            void display();
            void top_order();
            
            bool new_VNode(Vnode &a);
            bool new_ArcInfo(Arcinfo &a);
            bool delete_VNode(Vnode &a);
            bool delete_ArcInfo(Arcinfo &a);
            bool update_Vnode(Vnode &a);
            bool update_ArcInfo(Arcinfo &a);


            bool get_node(std::string &a,Vnode &out);
            bool get_arc(std::string from,std::string to,Arcinfo &out);

            int find_node(std::string &a);

    };
    
    bool AL_graph::new_VNode(Vnode &a){
        for(auto it : vertices){
            if(it.data == a.data)
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

    bool AL_graph::delete_ArcInfo(Arcinfo &a){
        auto it = std::find(infos.begin(),infos.end(),a);
        if(it == infos.end())   
            return 0;
        infos.erase(it);
        num_arc--;
        return 1; 
    }

    bool AL_graph::delete_VNode(Vnode &a){
        auto it = std::find(vertices.begin(),vertices.end(),a);
        if(it == vertices.end())
            return 0;
        vertices.erase(it);
        num_vex--;
        return 1;
    }

    bool AL_graph::update_Vnode(Vnode &a){
        auto it = vertices.begin();
        while(it != vertices.end()){
            if(it->data.name == a.data.name){
                *it = a;
                return 1;
            }
            it++;
        }
        return 0;
    }

    bool AL_graph::update_ArcInfo(Arcinfo &a){
        auto it = infos.begin();
        while(it != infos.end()){
            if(it->from == a.from && it->to == a.to){
                *it = a;
                return 1;
            }
            it++;
        }
        return 0;
    }

    
    bool AL_graph::get_node(std::string &a,Vnode &out){
        for(auto it : vertices){
            if(it.data.name == a){
                out = it;
                return 1;
            }
        }
        return 0;
    }

   bool AL_graph::get_arc(std::string from,std::string to,Arcinfo &out){
        for(auto it : infos){
            if(it.from == from && it.to == to){
                out = it;
                return 1;
            }
        }
        return 0;
    }

    int AL_graph::find_node(std::string &a){
        int i = 0;
        for(auto it : vertices){
            if(it.data.name == a)
                return  i;
            i++;
        }
        return num_vex;
    }
////////////////////////////////////////////
    void AL_graph::graph_ready(){
            all_weight = 0;
        for(auto i : vertices){
            i.in = 0;
            all_weight += i.data.scope;
            i.fir_arc = nullptr;
        }
        for(auto it : infos){
            vertices[find_node(it.to)].in += 1;
            auto from = vertices[find_node(it.from)].fir_arc;
            if(from == nullptr){
                vertices[find_node(it.from)].fir_arc = new ArcNode(find_node(it.to),it.weight);
                continue;
            }
            while(from->next_arc != nullptr){
                from = from->next_arc;
            }
            from->next_arc = new ArcNode(find_node(it.to),it.weight);
        }
    }

    void AL_graph::top_order(){
        this->graph_ready();
        std::vector<Vnode> non_in;
        std::vector<Vnode> U;
        for(auto it : vertices){
            if(it.in == 0)
                non_in.push_back(it);
        }
        while(!non_in.empty()){
            //std::sort(non_in.begin(),non_in.end());
            auto i = non_in.front().fir_arc;
            U.push_back(non_in.front());
            while(i != nullptr){
                vertices[i->adjvex].in -= 1;
                if(vertices[i->adjvex].in == 0){
                    non_in.push_back(vertices[i->adjvex]);
                }
                i = i->next_arc;
            }
            non_in.erase(non_in.begin());
        }
        result.swap(U);
        return;
    }
    
    void AL_graph::display(){
       
    }

}
