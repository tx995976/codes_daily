#include <iostream>
#pragma once 

template<class T>
class Node{
    protected:
        T data;
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
        Node<T> *head;
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
    this->next = nullptr; 
}

template<class T>
Node<T>::Node(const T &in){
    this->data = in;
    this->next = nullptr;
}

template<class T>
Node<T>::Node(const Node<T> &in){
    this->data = in.data;
    this->next = in.next;
}

template<class T>
SLstack<T>::SLstack(){
    this->head = new Node<T>;
}

template<class T>
int SLstack<T>::size(){
    int i = 0;
    auto temp = this->head->next;
    while(temp->next != nullptr){
        temp = temp->next;
        i++;
    }
    return i;
}
template<class T>
bool SLstack<T>::empty(){
    if(this->head->next == nullptr)
        return 1;
    else
        return 0;
}
template<class T>
int SLstack<T>::pop(T &i){
    auto temp = this->head->next;
    auto temp2 = temp->next;
    this->head->next = temp2;
    i = temp->data;
    delete temp;
}
template<class T>
int SLstack<T>::push(T &i){
    Node<T> * temp_in = new Node<T>(i);
    auto temp = this->head->next;
    this->head->next = temp_in;
    temp_in->next = temp;
}

template<class T>
T SLstack<T>::Top(){
    return this->head->next->data;
}

















