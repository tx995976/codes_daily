#include<iostream>

int array_used = 5;
int array_Va[5] = {3,6,7,8,9};
int * array_ptr = array_Va;

void table_insert(int temp){
    int pos = 0;
    array_used++;
    array_ptr = new (array_ptr) int [array_used];
    while(temp > array_Va[pos])
        pos++;
    for(int i = array_used;i > pos;i--)
        array_Va[i] = array_Va[i-1];
    array_Va[pos] = temp;
    return;
}

int main(){
    using namespace std;
    int temp;
    while(1){
        if(cin>>temp)
            table_insert(temp);
        else
            break;
    }
    for(int i = 0;i < array_used;i++)
        cout<<array_Va[i]<<" ";
    cout<<endl;
    delete(array_ptr);
    return 0;
}