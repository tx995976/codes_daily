#include <cstdio>
#include<iostream>
#include<stack>
#include <string>
#pragma once

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
            Btree(std::string input);
            ~Btree(){}
            void post_order();
            void post_order_re(TNode<T> *pt_this);
            void pre_order();
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
    void Btree<T>::post_order(){
        std::stack<TNode<T>> t_node;
        TNode<T> *pt_node = this->main_node;
        TNode<T> *pt_temp = pt_node;
    
        while(pt_temp != nullptr || !t_node.empty()){
            if(pt_temp != nullptr){
                t_node.push(*pt_temp);
                pt_temp = pt_temp->l_node;
            }
            else{
                t_node.pop(*pt_temp);
                if(pt_temp->r_node != nullptr){
                    pt_temp = pt_temp->r_node;
                    t_node.push(*pt_temp);
                 }
                else{
                    std::cout<<pt_temp->data<<" ";
                    pt_temp = pt_temp->l_node;
                }
            }
        }
    }
}
