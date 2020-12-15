#include<iostream>
#include<algorithm>

using namespace std;

struct num{
    int n;
    int position;
}   node[10000];
int temp;

bool compare(num a,num b){
    return a.n < b.n;
}

int main(){
    int t = 1;
    while(cin>>temp){
        node[t].n = temp;
        node[t].position = t;
        t++;
    }
    sort(node+1,node+t,compare);
    cout<<"min:"<<node[1].n<<" "<<"position:"<<node[1].position<<endl;
    cout<<"max:"<<node[t-1].n<<" "<<"position:"<<node[t-1].position<<endl;
    return 0;
}