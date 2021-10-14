#include"Linklist.hpp"
#include<iostream>


///////////////////////////////////////////////////////////////////

template<class ElemType>
Node<ElemType>::Node(){
    this->data =NULL;
    this->next =nullptr;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *link = nullptr){
    this->data = e;
    this->next = link;
}

///////////////////////////////////////////////////////////////////

template<class ElemType>
LinkList<ElemType>::LinkList(){
    this->head = new Node<ElemType>;
    this->length = 0;
}

template<class ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n){
    this->head = new Node<ElemType>;
    Node<ElemType> *temp = this->head;
    for(int i = 1;i <= n;i++){
        temp->next = new Node<ElemType>(v[i]);
        temp = temp->next;
        this->length++;
    }
}

template<class ElemType>
int LinkList<ElemType>::GetLength() const{
    return this->length;
}

template<class ElemType>
bool LinkList<ElemType>::IsEmpty() const{
    if(this->length == 0)
        return 1;
    else
        return 0;
}

template<class ElemType>
int LinkList<ElemType>::Locate(const ElemType &e) const{
    int i = 1;
    Node<ElemType> *temp = this->head->next;
    for(i;temp->data != e && temp != nullptr ;i++){
        temp = temp->next;
    }
    if(temp == nullptr)
        return -1;
    else
        return i;
}

template<class ElemType>
int LinkList<ElemType>::Get(int index,ElemType &e){
    if(index < 0||index >this->length){
        std::cerr<<"invaild_input"<<std::endl;
        return -1;
    }
    Node<ElemType> * temp = this->head->next;
    int i = 1;
    while(i != index){
        temp = temp->next;
        i++;
    }
    e = temp->data;
    return 0;
}

template<class ElemType>
int LinkList<ElemType>::Set(int index, const ElemType &e){
    if(index < 0||index > this->length){
        std::cerr<<"invaild_input"<<std::endl;
        return -1;
    }
   Node<ElemType> * temp = this->head->next;
     int i = 1;
    while(i != index){
        temp = temp->next;
        i++;
    }
     temp->data = e;
     return 0;
}

template<class ElemType>
int LinkList<ElemType>::Delete(int index, ElemType &e){
     if(index < 0||index > this->length){
         std::cerr<<"invaild_input"<<std::endl;
        return -1;
    }
    Node<ElemType> * temp = this->head->next;
    Node<ElemType> * temp_2 = this->head;
    int i = 1;
    while(i != index){
        temp_2 = temp_2->next;
        temp = temp->next;
        i++;
    }
    temp_2->next = temp->next;
    delete temp;
    this->length--;
    return 0;
}

template<class ElemType>
int LinkList<ElemType>::Insert (int index, const ElemType &e){
    if(index < 0){
         std::cerr<<"invaild_input"<<std::endl;
        return -1;
    }
    Node<ElemType> new_node(e);
    Node<ElemType> * temp = this->head->next;
    Node<ElemType> * temp_2 = this->head;
    if(index > this->length){
        std::cerr<<"auto insert in"<<this->length+1;
        index = this->length+1;
    }
    int i = 1;
    while(i != index){
        temp_2 = temp_2->next;
        temp = temp->next;
        i++;
    }
    new_node.next = temp;
    temp_2->next = new_node;
    this->length++;
    return 0;;
}


