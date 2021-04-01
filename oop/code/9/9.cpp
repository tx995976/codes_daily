#include<iostream>
 
using namespace std;

class vector_{
    protected:
        double x;
        double y;
    public:
        vector_(){}
        ~vector_(){}        
        vector_ operator + (const vector_ &other ){
            this->x += other.x;
            this->y += other.y;
            return ;
        }
};

