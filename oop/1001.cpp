#include<iostream>
#include<string>
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
    }  node_tree[3];

    int main(){
            stu node1,node2,node3;
            node_tree[0].stu_set("tom","tom@Gmail.com",18);
            node_tree[1].stu_set("jerry","jerry@Gmail.com",23);
            node_tree[2].stu_set("tx995976","tx995976@Gmail.com",19);
            for(int i = 0;i < 3;i++)
                node_tree[i].stu_show();
            return 0;
    }
