#include"Myclass.h"
	MyClass::MyClass(){
		x = 0;
		y = 0;
	}

	MyClass::MyClass(int a , int b ){ 
		x = a; 
		y = b; 
	} 
	void MyClass::Print() { 
		cout << "x = " <<this->x << endl; 
		cout << "y = " <<this->y << endl; 
	} 