#include<bits/stdc++.h>
using namespace std;
int main(){
    int N=10,hands,high,num=0,tmp;
    vector<int> apple;
    while(N > 0)
    {
        cin >> tmp;
        apple.push_back(tmp);
        N--;
    }
    cin>>hands;
    high=hands+30;
    for (int i = 0; i < 10; i++)
    {
        if (apple[i]<=high)
        {
            num=num+1;
        }
        
    }
    cout<<num;
    return 0;    
}
