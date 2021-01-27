#include<iostream>
#include<set>
#include<map>

using namespace std;

map<int,int> test4;
multiset<int> num;
/*void test(int a,int b){
    int a,b;
    std::cin>>a>>b;
    int c = a + b;
}
int test2(int a, int b){
    return 0;
}
int test3(int a, int b){
    if(a != b){
        return 0;
    }
    else return 1;

}*/


int main(){
    int a,b;
    cin>>a>>b;
    num.insert(a);
    num.insert(b);
    test4[15] = 45;
    cout<<num.count(a)<<endl;
    return 0;    
}