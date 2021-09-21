#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) 
    {        
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
         cout<<3<<endl<<12<<endl<<2;
    } else if (T == 4) {
        float a = 500;
        printf("%.3f",a/3);
    } else if (T == 5) {
        cout<<(260+220)/(12+20);
    } else if (T == 6) {
        cout<<sqrt(6*6+9*9);
    } else if (T == 7) {
        cout<<110<<endl<<90<<endl<<0<<endl;
    } else if (T == 8) {
        double b=3.141593;
        double r=5;
        cout<<b*r*2<<endl<<b*r*r<<endl<<4.0/3*b*r*r*r<<endl;
    } else if (T == 9) {
        int a1 = 1;
        for (size_t i = 0; i < 3; i++)
        {
            a1=(a1+1)*2;
        }
        cout<<a1;
        
    } else if (T == 10) {
        cout<<9;
    } else if (T == 11) {
        cout<<(double)(100.0/3);
    } else if (T == 12) {
        cout<<13<<endl<<"R"<<endl;
    } else if (T == 13) {
        double b=3.141593;
        double V1 = 4 * b * 64 / 3.0, V2 = 4 * b * 1000 / 3.0;
			cout << (int)pow(V1 + V2, 1 / 3.0);
    } else if (T == 14) {
        cout<<50;
    }
    return 0;
}