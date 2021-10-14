#pragma once

template <class ElemType>
struct Node{// 数据成员
    ElemType data; // 数据域
    Node<ElemType> *next; // 指针域
    //构造函数
    Node(); // 无参数的构造函数
    Node(ElemType e, Node<ElemType> *link = nullptr); // 已知数数据元素值和指针建立结构
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
