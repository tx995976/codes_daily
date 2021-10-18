#include <iostream>
#pragma once 

template<class T>
class Node{
    protected:
        T *data;
        Node<T> *next;
    public:
        Node();
        ~Node(){}
        Node(const Node<T> &i);
};

template<class T>
class SLstack{
    protected:
        int top;
        Node<T> *head;
        Node<T> *get_Top;
    public:
        ~SLstack(){}
        SLstack();
        
        int size();
        bool empty();
        int push(T &i);
        int pop(T &i);
        T Top(); 

};

















