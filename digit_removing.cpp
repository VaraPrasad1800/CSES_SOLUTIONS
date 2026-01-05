#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
   if(n==0){
      cout << 0 << endl;
   }
   else if(n<=9) cout << 1 << endl;
   else{
    vector<long long> v(n+1,LLONG_MAX-2);

    v[0] = 0;
    for(int i=1;i<=9;i++) v[i] = 1;

    for(int i=10;i<=n;i++){
        int k = i;
        long long ans = LLONG_MAX;
        while(k>0){
            int rem = k%10;
            ans = min(1+v[i-rem],ans);
            k = k/10;
        }
        v[i] = ans;
    }
    cout << v[n] << endl;
   }


}