#include<iostream>
#include<fstream>

#include<ctime>
#include<iomanip>

using namespace std;
class member{
        public:
                string id;
                string password;
                string name;
                double money;
        };
int main(){
    time_t a3 = 1619080326;
    time_t a4 = 1619080246;
    struct tm a1,a2;
    localtime_s(&a1,&a3);
    localtime_s(&a2,&a4);
    cout<<a2.tm_sec<<endl<<a1.tm_sec<<endl;
    

}