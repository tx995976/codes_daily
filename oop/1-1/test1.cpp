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
    //member a1("111111","5555","3333",3222.02);
    member a1;
    //test1.write((char *)&a1,sizeof (a1));
    //test1.close();
    if(!test)
        cout<<"error"<<endl;
    test.read((char *)&a1,sizeof(a1));
    cout<<a1.id<<a1.money<<a1.name<<endl;
    test.close();
    return 0;
}
