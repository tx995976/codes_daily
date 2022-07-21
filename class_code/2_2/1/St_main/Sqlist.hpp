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
public:
    ElemType *data; // 元素存储空间的首地址
public:
    SqList(int size = DEFAULT_SIZE); // 构造一个空表
    SqList(ElemType v[], int n, int size = DEFAULT_SIZE); // 根据数组 v 的内容构造顺序表
    virtual ~SqList(){} // 析构函数
    int GetLength() const; // 取顺序表长度
    bool IsEmpty() const; // 判断顺序表是否为空
    int Locate (const ElemType &e); // 元素定位，求指定元素在顺序表中的位置
    int Get (int i, ElemType &e); // 取顺序表 中第 i 个元素的值
    int Set (int i, const ElemType &e); // 修改顺序表中第 i 个元素的值
    int Delete (int i, ElemType &e); // 删除顺序表中第 i 个元素
    int Insert (int i, const ElemType &e); //在顺序表第 i 个位置插入元素
    int clear();
};

template <class ElemType>
int SqList<ElemType>::clear(){
    delete [] this->data;
    this->data = new ElemType[DEFAULT_SIZE];
    this->length = 0;
    return 0;
}

template <class ElemType>
SqList<ElemType>::SqList(int size){
    this->length = 0;
    this->maxLength = size;
    this->data = new ElemType[size];
    return;
}

template <class ElemType>
SqList<ElemType>::SqList(ElemType v[],int n,int size){
    ElemType* temp = new ElemType[size];
    for(int i = 0;i < n;i++){
        temp[i] = v[i];
    }
    this->length = n;
    this->maxLength = size;
    this->data = temp;
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
    if(i < 0||i >= this->length){
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
        std::cerr<<"invaild_input"<<std::endl;
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
        std::cerr<<"invaild_input"<<std::endl;
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
