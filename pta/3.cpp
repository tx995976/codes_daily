#include<iostream>
using namespace std;

int pa[6],line,eva,ma=0,mi,broken;

int main(){
    for(int i = 1;i <= 4 ; i++){    
        cin>>pa[i];
        ma = max(pa[i],ma);
    }
    cin>>line>>eva;
    for(int k = 1;k <= 4;k++)
        if(pa[k] < line||ma-pa[k] > eva)
            pa[5]=k,broken++;
    if(broken == 0)
        cout<<"Normal"<<endl;
    else if(broken == 1)
        cout<<"Warning: please check #"<<pa[5]<<"!"<<endl;
    else
        cout<<"Warning: please check all the tires!"<<endl;
    return 0;
}