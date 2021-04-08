#include<iostream>
 
using namespace std;

class vector_{
    protected:
        double x;
        double y;
    public:
        vector_(double x,double y){
            this->x = x;
            this->y = y;
        }
        vector_(){}
        ~vector_(){}   
        void show(){
            if(y < 0)
                cout<<x<<y<<"i"<<endl;
            else
                cout<<x<<"+"<<y<<"i"<<endl;
        }     
        vector_ operator + (const vector_ &other ){
            vector_ temp;
            temp.x = this->x + other.x;
            temp.y = this->y + other.y;
            return temp;
        }
        vector_ operator - (const vector_ &other){
            vector_ temp;
            temp.x = this->x - other.x;
            temp.y = this->y - other.y;
            return temp;
        }
        friend vector_  operator += (vector_ &it ,const vector_ &other);
        friend vector_  operator -= (vector_ &it ,const vector_ &other);

};

   vector_ operator += (vector_ & it ,const vector_ &other){
        it.x += other.x;
        it.y += other.y;
        return it;
   }

   vector_ operator -= (vector_ & it ,const vector_ &other){
        it.x -= other.x;
        it.y -= other.y;
        return it;
   }



    int main(){
        vector_ test1(2,2),test2(3,3),test3,test4;
        test3 = test1 + test2;
        test4 = test2 - test1;
        test3.show();
        test4.show(); 
        test3 += test4;
        test3.show();
        test3 -= test1;
        test3.show();
        return 0;
    }