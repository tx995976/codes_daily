#include<iostream>
#include<cmath>
using namespace std;

class Shape{
    public:
        virtual  ~Shape(){}
        Shape(){}    
        virtual double perimeter() = 0;   
        virtual double area() = 0;
        virtual void   show(){}   
};
class Rectangle: public Shape{
    private:
        double longth,width;
    public:
        ~Rectangle(){}        
        Rectangle(){}
        Rectangle(double longth,double width):Shape(){
            this->longth = longth;
            this->width = width;
        }
        double area(){
            return (this->longth * this->width);
        }
        double perimeter(){
            return (this->longth + this->width)*2;
        }
        void show(){
            cout<<"Rectangle:"<<endl<<"longth: "<<this->longth<<endl<<"width: "<<this->width<<endl;
        }
};
class Circle : public Shape{
    private:
        double R;
    public:
        ~Circle(){}
        Circle(){}
        Circle(double R):Shape(){
            this->R = R;
        }    
        double area(){
            return pow(this->R,2) * 3.14;
        }
        double perimeter(){
            return this->R * 2 * 3.14;
        }    
        void show(){
            cout<<"Circle:"<<endl<<"R: "<<this->R<<endl;
                
        }
};
class Square : public Rectangle{
    private:
        double length;
    public:
        ~Square(){}        
        Square(double length):Rectangle(){
            this->length = length;
        }
        double  area(){
            return pow(this->length,2);
        }
        double perimeter(){
            return this->length * 4;
        }
        void show(){
            cout<<"Square: "<<endl<<"length: "<<this->length<<endl;   
        }
};

int main(){
    Shape * test[]= {new Rectangle(3,4),new Circle(5),new Square(6)};
    for(int i = 0;i < 3;i++){
        test[i]->show();
        cout<<"perimeter: "<<test[i]->perimeter()<<endl<<"area: "<<test[i]->area()<<endl
            <<endl;
    }
    return 0;
}