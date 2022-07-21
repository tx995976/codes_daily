#include<iostream>
using namespace std;

const long long mod = 998244353;
int t,in;
long long result;

long long my_pow(long long a, long long b)
{    
	long long ans = 1;    
	 while (b){        
		if (b & 1)  {            
			ans *= a;            
			ans %= mod;        
		}        
		a *= a;        
		a %= mod;        
		b >>= 1;    
	} 
    return ans;
}
int main(){
    cin>>t;
    while(t-- > 0){
        cin>>in;
        result = ((my_pow(2,in>>1)-1)<<1)%mod;
        cout<<result<<"\n";
    }
}