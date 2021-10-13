#pragma once

const int DEFAULT_SIZE = 1000;
// 缺省元素个数
const int DEFAULT_INFINITY = 1000000;
// 缺省无穷大
template <class ElemType>
class SqList
{
protected:
    int length; // 顺序表的当前长度
    int maxLength; // 顺序表的最大容量
    ElemType *data; // 元素存储空间的首地址
public:
    SqList(int size = DEFAULT_SIZE); // 构造一个空表
    SqList(ElemType v[], int n, int size = DEFAULT_SIZE); // 根据数组 v 的内容构造顺序表
    virtual ~SqList(); // 析构函数
    int GetLength() const; // 取顺序表长度
    bool IsEmpty() const; // 判断顺序表是否为空
    int Locate (const ElemType &e); // 元素定位，求指定元素在顺序表中的位置
    int Get (int i, ElemType &e); // 取顺序表 中第 i 个元素的值
    int Set (int i, const ElemType &e); // 修改顺序表中第 i 个元素的值
    int Delete (int i, ElemType &e); // 删除顺序表中第 i 个元素
    int Insert (int i, const ElemType &e); //在顺序表第 i 个位置插入元素
};

