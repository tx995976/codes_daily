#include<iostream>
#include<cmath>
double a1;
double change(double);
int main(void)
{
    double a;
    using namespace std;
    cout<<"now let's us to do some\n "
    <<"please enter you data :";   
    cin>>a1;
    a=change(a1);
    cout<<"and zhe result is "<<a
        <<"\ngood!!";

}

   double change(double a6)
{
    double a2 = 3.1,a3 = 154.3,a4;
    if (a1<6/* condition */)
    {
        a4=a1*a2-a3;
    }
    else
    {
        a4=a1;
    }
    return a4;
}
