#include<iostream>
#include<fstream>
 
using namespace std;
class member{
        public:
                string id;
                string password;
                string name;
                double money;
        };

int main(){
    ifstream test("test.dat",ios::in|ios::binary);
    ofstream test1("test.dat",ios::out|ios::binary);
    member a1;
    a1.id = "3321";
    a1.password = "550";    
    a1.name = "tx995976";    
    a1.money = 652.3;
    //member a1;
    test1.write((char *)&a1,sizeof (a1));
    test1.close();
    //test.read((char *)&a1,sizeof(a1));
    //cout<<a1.id<<a1.money<<a1.name<<endl;
    test.close();
    return 0;
}
