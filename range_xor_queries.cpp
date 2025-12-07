#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n),left(n),right(n);
    int sum = 0;
    for(int i = 0;i<n;i++){
      cin >> v[i];
      sum^=v[i];
      left[i] = sum;
    }
    right[n-1] = v[n-1];
    for(int i =n-2;i>=0;i--){
        right[i] = v[i]^right[i+1];
    }
    while(k--){
        int a,b;
        cin >> a >> b;
        int ans = sum^(a-1>0?left[a-2]:0)^(b-1<n-1?right[b]:0);
        cout << ans << endl;
    }
    
    
}