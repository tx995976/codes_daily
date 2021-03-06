#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string front_tree,middle_tree;

void func_1(string front_tree,string middle_tree){
    if(front_tree.empty())
        return;
    string  front_left_tree,front_right_tree,middle_left_tree,middle_right_tree;
    char temp = front_tree[0];
    front_tree.erase(front_tree.begin());
    int k = middle_tree.find(temp);

    front_left_tree = front_tree.substr(0,k);
    front_right_tree = front_tree.substr(k);

    middle_left_tree = middle_tree.substr(0,k);
    middle_right_tree = middle_tree.substr(k+1);

    func_1(front_left_tree,middle_left_tree);
    func_1(front_right_tree,middle_right_tree);
    cout<<temp;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>middle_tree;
    cin>>front_tree;
    func_1(front_tree,middle_tree);
    cout<<endl;
    return 0;
}