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
        Node(const T &in);
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

template<class T>
Node<T>::Node(){
    this->data =nullptr;
    this->next = nullptr;
    
}


















