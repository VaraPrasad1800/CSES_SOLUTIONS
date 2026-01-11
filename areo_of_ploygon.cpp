#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
     ll l = 0;
     ll r = 0;
    for(int i=0;i<n;i++){
       l+= 1LL*v[i].first*v[(i+1)%n].second;
       r+= 1LL*v[i].second*v[(i+1)%n].first;
    }
    cout << abs(l-r) << endl;
}