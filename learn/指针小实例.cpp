#include<bits/stdc++.h>
int ID;
bool ISBN;
int main(){
    using namespace std;
    struct goods
    {
        string item;
        int id;
        long long isbn;
        double price; 
    };
    goods a1{"coke",1,6904724022406,3.0 },a0;
    goods a2{"cooike",2,6904724022407,2.5};
    goods a3{"noodles",3,6904732011545,4};
    cout<<"please enter zhe goods id:";
    cin>>ID;
    const goods * shop[4]={&a0,&a1,&a2,&a3};
    cout<<"zhe item is "<<shop[ID]->item<<" and the price is "<<shop[ID]->price<<endl;
    cout<<"you wanna the item's ISBN??:";
    cin>>ISBN;
    if (ISBN==1)
    {
        cout<<"zhe ISBN is "<<shop[ID]->isbn<<endl;
        return 0;
    }
    return 0;

    
    
    
    
    
}

  
