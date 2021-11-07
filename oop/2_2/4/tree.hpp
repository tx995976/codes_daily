#include<iostream>
#include<stack>
#pragma once

namespace my_tree{
    template<class T>
    class TNode{
        protected:
            T data;
            TNode<T> *l_node,*r_node;
        public:
            friend class tree;
            ~TNode(){}
            TNode(T data_in);
    };
    template<class T>
    class tree{
        protected:
            TNode<T> *main_node;
        public:
            tree();
            tree();
            ~tree(){}
            void post_order();
            void post_order_re();
            void pre_order();
            void find_ancestor(T &child);
            void clear();

    };


}