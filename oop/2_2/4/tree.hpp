#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <regex>
#include <vector>

namespace my_tree{

    template<class T>
    class TNode{
        public:
            T data;
            int deep = 0;
            TNode<T> *l_node,*r_node;
        public:
            ~TNode(){}
            TNode(){}
            TNode(T &data_in);
    };
 
    template<class T>
    class Btree{
        protected:
            TNode<T> *main_node;
        public:
            Btree();
            Btree(std::string &input);
            ~Btree(){}
            void setting_up(std::string &input);
            void pre_order();
            void post_order_re(TNode<T> *pt_this);
            int find_ancestor(T &child);
            void show_ancestor_deep(TNode<T> *pt_this,int &deep_in);
            void clear(TNode<T> *pt_this);
            TNode<T> *get_node()const; 
    };
    
    template<class T>
    TNode<T>::TNode(T &data_in){
        this->data = data_in;
        this->l_node = nullptr;
        this->r_node = nullptr;
    }

    template<class T>
    Btree<T>::Btree(){
        this->main_node = new TNode<T>();  
    }

    template<class T>
    Btree<T>::Btree(std::string &input){
        setting_up(input);
    }

    template<class T>
    TNode<T> *Btree<T>::get_node()const{
        return this->main_node;
    }

    template<class T>
    void Btree<T>::post_order_re(TNode<T> *pt_this){
        if(pt_this->l_node != nullptr)
            post_order_re(pt_this->l_node);
        if(pt_this->r_node != nullptr)
            post_order_re(pt_this->r_node);
        std::cout<<pt_this->data<<" ";
        return;
    }
    
    template<class T>
    void Btree<T>::pre_order(){
        std::stack<TNode<T>*> t_node;
        TNode<T> *pt_node = this->main_node;
        TNode<T> *pt_temp = pt_node;
        t_node.push(pt_temp);

        while(!t_node.empty()){
            t_node.pop(pt_temp);
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
        std::stack<TNode<T>*> t_node;
        TNode<T> *pt_temp = this->main_node,*pt_pre_node = nullptr;
        t_node.push(pt_temp);
        while(!t_node.empty()){
            t_node.pop(pt_temp);
            if(pt_temp->data == child){
                show_ancestor_deep(pt_temp->deep);
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
    void Btree<T>::show_ancestor_deep(TNode<T> *pt_this,int &deep_in){
        if(pt_this == nullptr)
            return;
        if(pt_this->deep < deep_in-1)
            show_ancestor_deep(pt_this->l_node,deep_in);
        show_ancestor_deep(pt_this->r_node,deep_in);
        std::cout<<pt_this->data<<" \0";
    }

    template<class T>
    void Btree<T>::setting_up(std::string &input){
        std::regex key("^(\\S+)[\\(\\),]");
        std::smatch result;

        std::vector<TNode<T>*> t_node;
        TNode<T> *pt_temp = nullptr;
        this->main_node = nullptr;

        int str_itor = 0,child_flag = 0,node_itor = -1;
        while(input[str_itor] != '\0'){
            switch(input[str_itor]){
                case '(':
                    node_itor++;
                    child_flag = 1;
                    t_node.push_back(pt_temp);
                    break;
                case ')':
                    node_itor--;
                    break;
                case ',':
                    child_flag = 2;
                    break;
                default :
                    std::regex_search(input,result,key);
                    pt_temp = new TNode<T>(result[1].str());
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
        t_node.clear();
    }

    template <class T>
    void Btree<T>::clear(TNode<T> *pt_this){
        if(pt_this == nullptr)
            return;
        clear(pt_this->l_node);
        clear(pt_this->r_node);
        delete pt_this;
    }
}


