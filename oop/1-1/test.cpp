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
    int i;
    time_t now,now2;
    now = time(NULL);
    char* t_now = ctime(&now);
    tm *now_t = localtime(&now);
    cout<<"tap to continue"<<endl;    
    cin>>i;
    time(&now2);
    time_t it = now2 - now;
    cout<<it<<endl;
}