#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

const int node = 1<<7+10;
class num{
    public:
    int str;
    int rank;
    bool operator < (const num& other) {
            return this->str > other.str;
        }
}player[node];

using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1;i <= (1<<n);i++)
        cin>>player[i].str,
        player[i].rank = i;
    sort(player+1,player+1+(1<<n-1));
    sort(player+1+(1<<n-1),player+1+(1<<n));
    if(player[1].str > player[(1<<n-1)+1].str)
        cout<<player[(1<<n-1)+1].rank<<endl;
    else
        cout<<player[1].rank<<endl;   
    return 0;
}