#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,q;
    cin >> n >> q;
    ll sum = 0;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        ll k ;
        cin >> k;
        sum+=k;
        v[i] = sum;
    }
    vector<ll> res(q);
    for(int i = 0;i<q;i++){
        int a,b;
        cin >> a >> b;
        ll ans = v[b-1] - ( a-1>0?v[a-2] : 0 );
        res[i] = ans;
    }
    for(auto i : res){
        cout << i << endl;
    }
}