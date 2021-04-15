#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class Point {
    public:
        Point()  {x = 0; y = 0; }
        Point(double xv,double yv) {x = xv;y = yv;}
        Point(Point& pt) { x = pt.x;  y = pt.y; }
        double getx() { return x; }
        double gety() { return y; }
        double Area() { return 0; }
        void Show() { cout<<"x="<<x<<' '<<"y="<<y<<endl; }
    private:
        double x,y;
};

class Rectangle : public Point {
    private:
        Point point_for_rectangle;
        double length,width;
    public:
        Rectangle(){}
        ~Rectangle(){}
        Rectangle(double point_x,double point_y,double length,double width):Point(point_x,point_y){
            this->length = length;
            this->width = width;
        }
        void cout_judge_by_point(Point input);
        double get_distance(Point input){
            return sqrt(pow(this->getx()-input.getx(),2)+pow(this->gety()-input.gety(),2));
        }
};


class Circle : public Point {
    private:
        Point Point_for_Circle;
        double R;
    public:
        Circle(){}    
        ~Circle(){}
        Circle(double point_x,double point_y,double R):Point(point_x,point_y){
            this->R = R;
        }
        void cout_judge_by_point(Point input);    
        double get_distance(Point input){
            return sqrt(pow(this->getx() - input.getx(),2) + pow(this->gety() - input.gety(),2));
        }
};


void Circle::cout_judge_by_point(Point input){
    if(get_distance(input) == this->R){
        cout<<"在圆上"<<endl;
    }
    else if(get_distance(input) < this->R){
        cout<<"在圆内"<<endl;
        this->Show();
        cout<<get_distance(input)<<endl;
    }
    else
        cout<<"在圆外"<<endl;
}
void Rectangle::cout_judge_by_point(Point input){
    if(input.getx() < this->getx()||input.gety() > this->gety())
        cout<<"在矩形外"<<endl;
    else if(input.getx() == this->getx()){
        if(get_distance(input) <= this->width)
            cout<<"在矩形上"<<endl;
        else
            cout<<"在矩形外"<<endl;
    }
    else if(input.gety() == this->gety()){
        if(get_distance(input) <= this->length)
            cout<<"在矩形上"<<endl;
        else

            cout<<"在矩形外"<<endl;
    }
    else
        cout<<"在矩形内"<<endl;
}

int main(){
    double point_x,point_y,length,width,R;
    system("chcp 65001");
    cout<<"Rectangle:  "<<endl;
    cin>>point_x>>point_y>>length>>width;
    Rectangle test_Rectangle(point_x,point_y,length,width);
    cout<<"test_point: "<<endl;
    cin>>point_x>>point_y;
    Point test_1(point_x,point_y);
    cout<<"result:"<<endl;
    test_Rectangle.cout_judge_by_point(test_1);

    cout<<"Circle:"<<endl;
    cin>>point_x>>point_y>>R;
    Circle test_Cricle(point_x,point_y,R);
    cout<<"test point:"<<endl;
    cin>>point_x>>point_y;
    Point test_2(point_x,point_y);
    cout<<"result:"<<endl;
    test_Cricle.cout_judge_by_point(test_2);
    return 0;
}



























