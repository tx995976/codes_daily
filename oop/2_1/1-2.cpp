#include<iostream>

const int array_size = 10;
int my_array[array_size] = {1,2,3,4,5,6,7,8,9,10};    

void array_reserve(int *array_temp){
    int temp;
    for(int i = 0;i < (array_size/2);i++){
        temp = array_temp[i];
        array_temp[i] = array_temp[(array_size-1-i)];
        array_temp[(array_size-1-i)] = temp;
    }
    return;
}


int main(){
    using namespace std;
    array_reserve(my_array);
    for(int i = 0;i < array_size;i++)
        cout<<my_array[i]<<" ";
    cout<<endl;
    return 0;
}