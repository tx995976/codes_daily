#include<iostream>
using namespace std; 
class IntArray {
public:
	IntArray(int sz);           // 数组初始化为sz个元素，初值全为0
    IntArray( int *array, int sz ) ;  // 用静态数组array的前sz个元素初始化新数组
    IntArray( const IntArray &rhs ) ; // 拷贝构造函数
    ~IntArray(){}
    void printAll();
    void set_member(int size ,int *control);
private:
	int *ia = NULL; //////////////////////
	int size;
};
    IntArray::IntArray( int sz ) { 
        set_member(sz,this->ia);
    }
    IntArray:: IntArray( int *array, int sz ) { 
        set_member(sz,array);
    }
    IntArray:: IntArray( const IntArray &rhs ) { 
        set_member(rhs.size,rhs.ia);
    }

    void IntArray::printAll()
    {
    for ( int ix=0; ix < size; ++ix ) 
        cout<<ia[ix]<<"  ";    
    cout<<endl;
    }
 
    void IntArray::set_member(int size_ ,int *control){
        this->ia = new int [size_];
        this->size = size_;
        if(control == NULL)
            for(int i = 0;i < size_;i++)
                ia[i] = 0;
        else
            for(int i = 0;i < size_;i++)
                ia[i] = control[i];
            
    }

int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	IntArray arr1(10), arr2(a,5),arr3(arr2);
	arr1.printAll();
	arr2.printAll();
	arr3.printAll();
	return 0;
}
