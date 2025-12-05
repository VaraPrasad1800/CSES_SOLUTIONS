#include<bits/stdc++.h>
using namespace std;
long long val = 1000000007;
long long power(long long base,int x){
   if(x == 0) return 1;
   if(x==1) return base;
   if(x%2==0){
    return (power((base*base)%val,x/2));
   }
   else{
    return (base*power(base,x-1))%val;
   }
}



int main(){
   int t;
   cin >> t;
   while(t--){
    int a,b,c;
    cin >> a >> b >> c;
    long long ans = power(a,b);
    cout << ans << endl;
   }
}