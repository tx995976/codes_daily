#include<iostream>
#include<cmath>

using namespace std;
class myPoint {  
   public:
   myPoint(double x0=0.0,double y0=0.0):x(x0),y(y0) {}
   myPoint(myPoint &np):x(np.x),y(np.y) {}
      double GetX() { return x;}
      double GetY() {return y;}
      void SetX(double x0) {x=x0;}
      void SetY(double y0) {x=y0;} 
      void SetPoint(double x0,double y0) {x=x0;y=y0;}
      void SetPoint(myPoint &np) { x=np.x; y=np.y;}
      double  GetLength(myPoint p) {
         return sqrt((x-p.x)*(x-p.x) +(y-p.y)*(y-p.y));
      }
      void Printit() { cout<<" ("<<x<<","<<y<<") ";}
   private:
      double x ,y;
};
class Triangle{
   myPoint p1,p2,p3;
   public:
   Triangle(double p1_x,double p1_y,double p2_x,double p2_y,double p3_x,double p3_y){
      p1.SetX(p1_x);
      p1.SetX(p1_y);
      p2.SetX(p2_x);
      p2.SetX(p2_y);
      p3.SetX(p3_x);
      p3.SetX(p3_y);
   }
   Triangle(){}
   ~Triangle(){}

   double get_length(){
      return this->p1.GetLength(p2)+this->p1.GetLength(p3)+this->p2.GetLength(p3);
   }
   double get_sqrt(){   
         double a = this->p2.GetLength(p3),b = this->p1.GetLength(p3),c = p1.GetLength(p2);
         double p = (a+b+c)/2;
         return sqrt(p*(p-a)*(p-b)*(p-c));
   }

};

int main(){
   Triangle test;




   return 0;
}












