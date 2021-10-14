#include"Sqlist.hpp"
#include<iostream>

template <class ElemType>
SqList<ElemType>::SqList(int size = DEFAULT_SIZE){
    this->length = 0;
    this->maxLength = size;
    this->*data = new ElemType[size];
    return;
}

template <class ElemType>
SqList<ElemType>::SqList(ElemType v[],int n,int size = DEFAULT_SIZE){
    ElemType* temp = new ElemType[size];
    for(int i = 0;i < n;i++){
        temp[i] = v[i];
    }
    this->length = n;
    this->maxLength = size;
    this->*data = temp;
}

template <class ElemType>
int SqList<ElemType>::GetLength() const{
    return this->length;
}

template<class ElemType>
bool SqList<ElemType>::IsEmpty() const{
    if(this->length <= this->maxLength)
        return 1;
    else
        return 0;
}

template <class ElemType>
int SqList<ElemType>::Locate(const ElemType &e){
    for(int i = 0;i < this->length;i++){
        if(this->data[i] == e){
            return i;
        }
    }
    return -1;
}

template<class ElemType>
int SqList<ElemType>::Get(int i,ElemType &e){
    if(i < 0||i >= this->maxLength){
        std::cerr<<"vaild_input"<<std::endl;
        return -1;
    }
    else
        e = this->data[i];
    return 0;
}

template<class ElemType>
int SqList<ElemType>::Set(int i, const ElemType &e){
    if(i < 0||i >= this->maxLength){
        std::cerr<<"invaild_input"<<std::endl;
        return -1;
    }
    else
        this->data[i] = e;
    return 0;
}

template<class ElemType>
int SqList<ElemType>::Delete(int i, ElemType &e){
    if(i < 0||i >= this->maxLength){
        std::cerr<<"invaild_input"<<std::endl
        return -1;
    }
    else if(i >= this->length){
        std::cerr<<"no_data"<<std::endl;
        return -1;
    }
    else{
        for(int y = i;y <= this->length;y++)
            this->data[y] = this->data[y+1];
        this->length--;
    }
    return 0;
}

template<class ElemType>
int SqList<ElemType>::Insert(int i,const ElemType &e){
    if(this->length >= this->maxLength){
        std::cerr<<"full!"<<std::endl;
        return -1;
    }
    else if(i < 0||i >= this->maxLength){
        std::cerr<<"invaild_input"<<std::endl
        return -1;
    }
    else if(i > this->length){
        std::cerr<<"auto insert in "<<(this->length)<<std::endl;
        this->data[this->length] = e;
        this->length++;
        return 0;
    }
    else{
        for(int temp = this->length;temp >= i;temp--){
            this->data[temp+1] = this->data[temp];
        }
        this->data[i] = e;
        this->length++;
    }
    return 0;
}













