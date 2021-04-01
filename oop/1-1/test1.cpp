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
    member a1;
    ifstream test("test.dat",ios::in|ios::binary);//////////????????????????
    test.read((char*)&a1, sizeof(a1));
    cout<<a1.id<<" "<<a1.money<<a1.name<<endl;
    test.close();
    return 0;
}
