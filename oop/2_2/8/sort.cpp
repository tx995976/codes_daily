#include <iostream>
#include <algorithm>
#include <string>

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
                if(_sum != r._num)
                    return _sum < r._sum;
                if(math != r.math)
                    return math < r.math;
                return _num < r._num;
            }            
    };
}



