#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll>& v, ll n,ll k,ll mid) {
    ll parts = 1;
    ll Sum = 0;
    for (int i =0;i<n; i++) {
        Sum +=v[i];
        if (Sum>mid) {
            parts++;
            Sum=v[i];
        }
    }
    return parts <= k;
}

int main() {
    ll n,k;
    cin >> n>> k;

    vector<ll> v(n);
    ll low=0,high=0;

    for (int i=0;i<n;i++) {
        cin >>v[i];
        low = max(low,v[i]);
        high +=v[i];
    }
    ll ans=high;

    while(low<=high){
        ll mid = low+(high-low)/2;
        if(check(v, n, k, mid)) {
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
}
