#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll val = 1000000007;

ll two_power(ll base,ll n){
    if(n == 0) return 1;
    if(n == 1) return base;
    if(n%2==0){
        return (two_power((base*base)%val,n/2))%val;
    }
    else{
        return (base*(two_power(base,n-1))%val)%val;
    }
}

int main(){
    long long n;
    cin >> n;
    long long val = 1000000007;
   
     long long power = (two_power(2,n))%val;
     cout << power << endl;
}