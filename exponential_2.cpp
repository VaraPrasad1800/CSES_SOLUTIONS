#include<bits/stdc++.h>
using namespace std;
long long val = 1000000007;
long long power(long long base,long long x,long long val){
   if(x == 0) return 1;
   if(x==1) return base;
   if(x%2==0){
    return (power((base*base)%val,x/2,val))%val;
   }
   else{
    return (base*power(base,x-1,val))%val;
   }
}



int main(){
   int t;
   cin >> t;
   while(t--){
    long long a,b,c;
    cin >> a >> b >> c;
    long long ans = power(b,c,val-1);
     ans = power(a,ans,val);
    cout << ans << endl;
   }
}