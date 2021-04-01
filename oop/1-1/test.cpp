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
    time_t now;
    now = time(NULL);
    char* t_now = ctime(&now);
    tm *now_t = localtime(&now);
    cout<<(1&654)<<endl;    
    
}