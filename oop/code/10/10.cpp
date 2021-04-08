#include<iostream>
#include<stack>
using namespace std;
const int MaxSize = 100; // 栈中能保存的最多元素个
    
    
    
    
    template<class t>
    class Istack{
        public:
            Istack();           // 栈的构造函数
            ~Istack();         // 栈的析构函数
            void Push(const t &n);    // 往栈顶增加元素
            void Pop();          // 从非空栈的栈顶删除一个元素
            t GetTop();       // 返回非空栈的栈顶元素
            bool Empty();      // 判断栈是否为空
            int Size();         // 返回栈中元素的个数
            void ClearStack();  // 将栈清空
        private:
            t elem[MaxSize];  // 保存栈中各元素的数组
            int Top;          // 保存栈顶的当前位置
            
    };

    template<class t>
    Istack<t>::Istack(){
        this->Top = 0;
    }

    template<class t>
    void Istack<t>::Push(const t &n){
        elem[Top++] = n;
    }

    template<class t>
    void Istack<t>::Pop(){
        if(Top == 0 )
            cout<<"it's empty!"<<endl

        else{
            int temp = Top
            elem[--Top] = elem[temp];
        }
    }

    template<class t>
    t Istack<t>::GetTop(){
        return elem[Top-1];
    }

    template<class t>
    bool Istack<t>::Empty(){
        if(Top == 0)
            return 1;
        else
            return 0;
    }

    template<class t>
    int Istack<t>::Size(){
        return Top-1;        
    }

    template<class t>
    void Istack<t>::ClearStack(){
        for(int i = Top-1,;i >= 0;i--)
            elem[i] = elem[Top];
        Top = 0;
    }