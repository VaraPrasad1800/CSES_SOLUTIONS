#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    ll maxE = 0;
    ll max_xor = 0;
    for(int i = 0;i<n;i++){
         cin >> v[i];
         maxE = max(maxE,v[i]);
         max_xor^=v[i];   
    } 
    max_xor = max(max_xor,maxE);
    
    for(int k = 2;k<n;k++){
      ll Xor = 0;
        for(int i =0;i<k;i++){
            Xor^=v[i];
        }
        max_xor = max(max_xor,Xor);
        for(int i = k;i<n;i++){
            Xor = Xor^v[i]^v[i-k];
            max_xor = max(max_xor,Xor);
        }
    }
    cout << max_xor << endl;
}
