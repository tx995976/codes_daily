#include<iostream>

using namespace std; 
#ifndef Myclass

	class MyClass { 
		public: 
		MyClass();
		MyClass(int a , int b); 
		void Print(); 
	private: 
		int x, y; 
	}; 

#endif