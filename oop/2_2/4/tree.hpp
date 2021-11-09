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
            void pre_order();
            void post_order_re(TNode<T> *pt_this);
            void find_ancestor(T &child);
            void clear();
            TNode<T> *get_node(); 
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
    TNode<T> *Btree<T>::get_node(){
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
    void Btree<T>::find_ancestor(T &child){
            
    }

    template<class T>
    Btree<T>::Btree(std::string &input){
        std::regex key("(\\S+)[\\(\\),]");
        std::smatch result;
        
        TNode<T> *pt_temp = nullptr;
        int str_itor = 0,child_flag = 0,node_itor = -1;
        std::vector<TNode<T>*> t_node;
        while(input[str_itor] != '\0'){
            switch(input[str_itor]){
                case '(':
                    node_itor++;
                    t_node.push_back(pt_temp);
                    child_flag = 1;
                    break;
                case ')':
                    node_itor--;
                    break;
                case ',':
                    child_flag = 2;
                    break;
                default :
                    std::regex_search(input[str_itor]+1,input.end(),result,key);
                    cout<<input[1];
                    pt_temp = new TNode<T>();
            }

        }
    }
}
