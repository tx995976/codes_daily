#include <iostream>
#include <algorithm>
#include <string>
#include<vector>

namespace my_sort {

    class stu{
        private:
            std::string name;
            int _num;
            int _sum;
            int math,chinese,english;
        public:
            stu(){}
            ~stu(){}
            stu(std::string a,int b,int c,int d,int f){
                name = a;
                _num = b;
                chinese = c;
                math = d;
                english = f;

                _sum = chinese + math + english; 
            }
            
            bool operator< (const stu &r)const{
                if(_sum != r._sum)
                    return _sum < r._sum;
                if(math != r.math)
                    return math < r.math;
                return _num < r._num;
            }

            bool operator> (const stu &r)const{
                if(_sum != r._sum)
                    return _sum > r._sum;
                if(math != r.math)
                    return math > r.math;
                return _num > r._num;
            }


            void print(){
                printf("%s %d %d\n",name.c_str(),_num,_sum);
            }            
    };

    template<class T>
    void heap_sift_down(std::vector<T> &input,int start,int end){
        int father = start;
        int child = father * 2 + 1;
        while(child <= end){
            if(child+1 <= end && input[child] < input[child+1])
                child++;
            if(input[father] > input[child])
                return;
            else{
                std::swap(input[father],input[child]);
                father = child;
                child = father * 2 + 1;
            }
        }
    }
    //接受顺序迭代器
    template<class T>
    void sort(std::vector<T> &input){
        int len = input.size();
        for(int i = (len - 2)/2;i >= 0;i--)
            heap_sift_down(input,i,len-1);
        for(int i = len - 1;i > 0;i--){
            std::swap(input[0],input[i]);
            heap_sift_down(input,0,i-1);
        }
    }
};