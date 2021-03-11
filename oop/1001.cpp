#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

    class stu{
        private:
            string name;
            string email;
            int age;
        public:
            void stu_set(string a,string b,int c){
                this->age = c;
                this->email = b;
                this->name = a;
            }
            void stu_show(){
                cout<<this->name<<" "<<this->age<<" "<<this->email<<endl;
            }
            bool operator < (const stu &other){
                    return this->age < other.age;
            }
    };
    vector<stu> data_stu;

    int main(){
            stu node1,node2,node3;
            node1.stu_set("tom","tom@Gmail.com",18);
            node2.stu_set("jerry","jerry@Gmail.com",23);
            node3.stu_set("tx995976","tx995976@Gmail.com",19);
            data_stu.push_back(node1);
            data_stu.push_back(node2);
            data_stu.push_back(node3);
            sort(data_stu.begin(),data_stu.end());
            for(int i = 0;i < data_stu.size();i++)
                data_stu[i].stu_show();
            return 0;
    }
