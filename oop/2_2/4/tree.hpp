#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <regex>
#include <vector>

namespace my_tree{
    const int DEFAULT_size = 100;

    
    class TNode{
        public:
            std::string data;
            int deep = 0;
            TNode *l_node,*r_node;
        public:
            ~TNode(){}
            TNode(){}
            TNode(std::string data_in);
    };
 
    template<class T>
    class Btree{
        protected:
            TNode *main_node;
        public:
            Btree();
            Btree(std::string &input);
            ~Btree(){}
            void setting_up(std::string &input);
            void pre_order();
            void post_order_re(TNode *pt_this);
            int find_ancestor(T &child);
            void show_ancestor_deep(TNode *pt_this,int &deep_in);
            void clear(TNode *pt_this);
            TNode *get_node()const; 
    };
    
   
    TNode::TNode(std::string data_in){
        this->data = data_in;
        this->l_node = nullptr;
        this->r_node = nullptr;
    }

    template<class T>
    Btree<T>::Btree(){
        this->main_node = new TNode();  
    }

    template<class T>
    Btree<T>::Btree(std::string &input){
        setting_up(input);
    }

    template<class T>
    TNode *Btree<T>::get_node()const{
        return this->main_node;
    }

    template<class T>
    void Btree<T>::post_order_re(TNode *pt_this){
        if(pt_this->l_node != nullptr)
            post_order_re(pt_this->l_node);
        if(pt_this->r_node != nullptr)
            post_order_re(pt_this->r_node);
        std::cout<<pt_this->data<<" ";
        return;
    }
    
    template<class T>
    void Btree<T>::pre_order(){
        std::stack<TNode*> t_node;
        TNode *pt_node = this->main_node;
        TNode *pt_temp = pt_node;
        t_node.push(pt_temp);

        while(!t_node.empty()){
            pt_temp = t_node.top();
            t_node.pop();
            std::cout<<pt_temp->data<<" ";
            if(pt_temp->l_node != nullptr)
                t_node.push(pt_temp->l_node);
            if(pt_temp->r_node != nullptr)
                t_node.push(pt_temp->r_node);
        }
        std::cout<<"\n";
    }

    template<class T>
    int Btree<T>::find_ancestor(T &child){
        std::stack<TNode*> t_node;
        TNode *pt_temp = this->main_node,*pt_pre_node = nullptr;
        t_node.push(pt_temp);
        while(!t_node.empty()){
            pt_temp = t_node.top();
            t_node.pop();
            if(pt_temp->data == child){
                show_ancestor_deep(get_node(),pt_temp->deep);
                return pt_temp->deep;
            }
            if(pt_temp->l_node != nullptr)
                t_node.push(pt_temp->l_node);
            if(pt_temp->r_node != nullptr)
                t_node.push(pt_temp->r_node);
        }
        return 0;
    }

    template<class T>
    void Btree<T>::show_ancestor_deep(TNode *pt_this,int &deep_in){
        if(pt_this == nullptr)
            return;
        if(pt_this->deep < deep_in-1)
            show_ancestor_deep(pt_this->l_node,deep_in);
        show_ancestor_deep(pt_this->r_node,deep_in);
        std::cout<<pt_this->data<<" \0";
    }

    template<class T>
    void Btree<T>::setting_up(std::string &input){
        std::regex key("^(\\S+?)[\\(\\),]");
        std::smatch result;

        TNode* t_node[DEFAULT_size];
        TNode *pt_temp = nullptr;
        this->main_node = nullptr;

        int str_itor = 0,child_flag = 0,node_itor = -1;
        while(input[str_itor] != '\0'){
            switch(input[str_itor]){
                case '(':
                    node_itor++;
                    child_flag = 1;
                    t_node[node_itor] = pt_temp;
                    break;
                case ')':
                    node_itor--;
                    break;
                case ',':
                    child_flag = 2;
                    break;
                default :
                    std::regex_search(input,result,key);
                    pt_temp = new TNode(result[1]);
                    input.erase(0,result[1].length()-1);
                    if(this->main_node == nullptr){
                        this->main_node = pt_temp;
                    }
                    else{
                        switch(child_flag){
                            case 1:
                                t_node[node_itor]->l_node = pt_temp;
                                pt_temp->deep = t_node[node_itor]->deep+1;
                                break;
                            case 2:
                                t_node[node_itor]->r_node = pt_temp;
                                pt_temp->deep = t_node[node_itor]->deep;
                                break;
                        }
                    }
            }
            input.erase(0,1);
        }
    }

    template <class T>
    void Btree<T>::clear(TNode *pt_this){
        if(pt_this == nullptr)
            return;
        clear(pt_this->l_node);
        clear(pt_this->r_node);
        delete pt_this;
    }
}


