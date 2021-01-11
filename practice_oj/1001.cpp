#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<iomanip>
using namespace std;

class food{
    public:
    int beans;
    int cat_foods;
    double ratio;
    double dig(){
        if(this->cat_foods != 0)
            return double(this->beans)/double(this->cat_foods);
        else
            return 9999999;
    } 
};

vector<food> mouse;
food temp;

bool compare(food a,food b){
    return a.ratio>b.ratio;
}

double buy(int n,int i = 0){
    double ans = 0;
    while(n != 0 && i != mouse.size()){
        if(mouse[i].ratio == 9999999)
            ans += mouse[i].beans;
        else if(mouse[i].cat_foods > n)
            ans += mouse[i].ratio*n,n=0;
        else
            ans += mouse[i].beans,n-=mouse[i].cat_foods;
        i++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("123.txt","w",stdout);
    int n,m;
    while(cin>>n>>m){
        if(n == -1)
            break;
        for(int i = 1;i <= m;i++){
            cin>>temp.beans>>temp.cat_foods;
            temp.ratio=temp.dig();
            mouse.push_back(temp);
        }
        sort(mouse.begin(),mouse.end(),compare);
        printf("%.3f\n",buy(n));
        //cout<<setiosflags(ios::fixed)<<setprecision(3)<<buy(n)<<"\n";
        //cout<<setiosflags(ios::fixed)<<setprecision(3)<<buy(n)<<endl;
        mouse.clear();
    }
return 0;
}