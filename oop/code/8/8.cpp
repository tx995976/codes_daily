#include<iostream>
#include<cmath>
#include<vector>


using namespace std;

class Circle :public Geometric_shape {
    protected:
            double R;
    public:
        Circle(){}
        Circle(double R){
            this->R = R;
        }        
        ~Circle(){}
        void show(){
            cout<<this->R<<endl;
        }    
        double perimeter(){
            return 2*this->R*3.14;
        }

        double area(){
            return 3.14 * pow(this->R,2);
        }

        double volume(){
            return 0;
        }
};  
class Rectangle: public Geometric_shape{
    protected:
        double longth,width;
    public:
        Rectangle(){}        
        ~Rectangle(){}
        Rectangle(double longth,double width){
            this->longth = longth;
            this->width = width;
        }
        void show(){
            cout<<this->longth<<" "<<this->width<<endl;
        }    
        double permeter(){
            return 2*(this->longth + this->width);
        }    
        double area(){
            return this->longth *this->width;
        }
        double volume(){
            return 0;
        }

};
class Triangle: public Geometric_shape{
    protected:
        double l1,l2,l3;
    public:        
        ~Triangle(){}
        Triangle(double l1,double l2, double l3){
            this->l1 = l1;                
            this->l2 = l2;                
            this->l3 = l3;                    
        }
        void show(){
            cout<<this->l1<<" "<<this->l2<<" "<<this->l3<<endl;
        }        
        double perimeter(){
            return this->l1+this->l2+this->l3;
        }
        double area(){
            double a = this->l1,b = this->l2,c =this->l3;
            double p = (a+b+c)/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }
        double volume(){
            return 0;
        }
};
class Box : public Rectangle {
    protected:
        double H;
    public:
        ~Box(){}    
        Box(double longth,double width,double H):Rectangle(longth,width){
            this->H = H;
        }
        void show(){
            cout<<this->H<<" "<<this->longth<<" "<<this->width<<endl;
        }
        double perimeter(){
            return Rectangle::permeter();
        }
        double area(){
            return Rectangle::area();
        }
        double volume(){
            return Rectangle::area() * this->H;
        }

};
class Cylinder: public Circle {
    protected:
        double H;
    public:
        ~Cylinder(){}
        Cylinder(double R,double H):Circle(R){
            this->H = H;
        }        
        void show(){
            cout<<this->R<<" "<<this->H<<endl;
        }
        double perimeter(){
            return Circle::perimeter();
        }
        double area(){
            return Circle::area();
        }
        double volume(){
            return Circle::area() * this->H;
        }
};
class Cone: public Circle{
    protected:
        double H;
    public:
        ~Cone(){}            
        Cone(double R,double H):Circle(R){
            this->H = H;
        }    
        void show(){
            cout<<this->R<<" "<<this->H<<endl;
        }
        double perimeter(){
            return Circle::perimeter();
        }
        double area(){
            return Circle::area();
        }
        double volume(){
            return (Circle::area() * this->H)/3;   
        }
};
class T_pyramid:public Triangle{
    protected:
        double H;
    public:
        ~T_pyramid(){}
        T_pyramid(double l1,double l2,double l3,double H):Triangle(l1,l2,l3){
            this->H = H;
        }  
        void show(){
            cout<<this->l1<<" "<<this->l2<<" "<<this->l3<<" "<<this->H<<endl;
        }        
        double perimeter(){
            return Triangle::perimeter();
        }
        double area(){
            return Triangle::area();
        }
        double volume(){
            return (this->H * Triangle::area())/3;
        }
};
class T_prism:public Triangle{
    protected:
        double H;
    public:
        ~T_prism(){}
        T_prism(double l1,double l2,double l3,double H):Triangle(l1,l2,l3){
            this->H = H;
        }
        void show(){
            cout<<this->l1<<" "<<this->l2<<" "<<this->l3<<" "<<this->H<<endl;
        }        
        double perimeter(){
            return Triangle::perimeter();
        }
        double area(){
            return Triangle::area();
        }
        double volume(){
            return this->H * Triangle::area();
        }
};
class Geometric_shape{
    public:
       virtual void show(){}
       virtual double perimeter(){}
       virtual double area(){}
       virtual double volume(){}
};
int main()
{
	Geometric_shape * gs[]={
        new	Circle(10),new Rectangle(6,8),new Triangle(3,4,5),
        new Box(6,8,3),new Cylinder(10,3),new Cone(10,3),
        new T_pyramid(3,4,5,3),new T_prism(3,4,5,3)
        };
    for (int i=0;i<8;i++)
	{
		gs[i]->show();
        cout<<endl;
	}
	cout<<"平面图形："<<endl;
    for (int i=0;i<3;i++)
	   {
		   cout<<"图形周长："<<gs[i]->perimeter()<<'\t';
        cout<<"图形面积："<<gs[i]->area()<<'\t';
        cout<<"图形体积："<<gs[i]->volume()<<endl;
    }
	cout<<"立体图形："<<endl;
    for (int i=3;i<8;i++)
	   {
		   cout<<"图形底周长："<<gs[i]->perimeter()<<'\t';
        cout<<"图形底面积："<<gs[i]->area()<<'\t';
        cout<<"图形体积  ："<<gs[i]->volume()<<endl;
    }
	return 0;
}
