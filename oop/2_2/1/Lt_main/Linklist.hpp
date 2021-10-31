#include<iostream>
#pragma once

template <class ElemType>
struct Node{// 数据成员
    ElemType data; // 数据域
    Node<ElemType> *next; // 指针域
    //构造函数
    Node(); // 无参数的构造函数
    Node(ElemType e, Node<ElemType> *link); // 已知数数据元素值和指针建立结构
};

template <class ElemType>
class LinkList
{
protected:
//单链表的数据成员
    Node<ElemType> *head; // 头结点指针
    int length; // 单链表长度
public:
    //单链表的函数成员
    LinkList(); // 无参数的构造函数
    LinkList(ElemType v[], int n); //有参数的构造函数
    virtual ~LinkList(); // 析构函数
    int GetLength() const; // 求单链表长度
    bool IsEmpty() const; // 判断单链表是否为空
    int Locate (const ElemType &e) const; // 元素定位
    int Get (int index, ElemType &e); // 求指定位置的元素
    int Set (int index, const ElemType &e); // 设置指定位置的元素值
    int Delete (int index, ElemType &e); // 删除元素
    int Insert (int index, const ElemType &e); // 在制定位置插入元素
};

template<class ElemType>
Node<ElemType>::Node(){
    this->next =nullptr;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *link){
    this->data = e;
    this->next = link;
}

///////////////////////////////////////////////////////////////////

template<class ElemType>
LinkList<ElemType>::~LinkList(){}

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
    e = temp->data;
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
    Node<ElemType> * new_node = new Node<ElemType>(e,nullptr);
    Node<ElemType> * temp = this->head->next;
    Node<ElemType> * temp_2 = this->head;
    if(index > this->length){
        index = this->length+1;
    }
    int i = 1;
    while(i != index){
        temp_2 = temp_2->next;
        temp = temp->next;
        i++;
    }
    new_node->next = temp;
    temp_2->next = new_node;
    this->length++;
    return 0;;
}