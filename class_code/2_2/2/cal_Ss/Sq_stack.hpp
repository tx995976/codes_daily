#include<iostream>


#pragma once

const int DEFAULT_SIZE = 100;

template<class T>
class Sqstack{
    protected:
        int top;
        int max_size;
        T  *data;;
    public:
        Sqstack(const Sqstack<T> &array_T);
        Sqstack(int size = DEFAULT_SIZE);
        ~Sqstack(){}

        int size();
        bool empty();
        T Top();
        int push(T &i);
        int pop(T &i);

        Sqstack<T> &operator = (const Sqstack<T> &value_r);
};


template<class T>
Sqstack<T>::Sqstack(int size){
    this->max_size = size;
    this->data = new T [size];
    this->top = 0;
}

template<class T>
Sqstack<T>::Sqstack(const Sqstack<T> &array_T){
    this->data = nullptr;
    this = array_T;
}

template<class T>
int Sqstack<T>::size(){
    return this->top;
}

template<class T>
T Sqstack<T>::Top(){
    return this->data[this->top-1];
}

template<class T>
int Sqstack<T>::pop(T &i){
    if(this->empty()){
        std::cout<<"empty!"<<std::endl;
        return -1;
    }
    i = this->data[--this->top];
    return 0;
}

template<class T>
int Sqstack<T>::push(T &i){
    if(this->top > this->max_size){
        std::cout<<"full!"<<std::endl;
        return -1;;
    }
    this->data[this->top++] = i;
    return 0;
}

template<class T>
bool Sqstack<T>::empty(){
    if(this->top == 0)
        return 1;
    else
        return 0;
}

template<class T>
Sqstack<T> &Sqstack<T>::operator=(const Sqstack<T> &value_r){
    delete this->data;
    this->max_size = value_r.max_size;
    this->data = new T [this->max_size];
    for(int i = 0;i < value_r.top;i++)
        this->data[i] = value_r.data[i];
}













