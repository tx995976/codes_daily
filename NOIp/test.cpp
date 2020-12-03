#include<iostream>
#include<set>

using namespace std;
using set_itor = set<int>::iterator;

set<int> test4;
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
    set_itor it;
    int a,b;
    cin>>a>>b;
    test4.insert(a);
    test4.insert(b);
    it = test4.begin();
    cout<<*it<<" "<<*(++it)<<endl;
    return 0;    
}