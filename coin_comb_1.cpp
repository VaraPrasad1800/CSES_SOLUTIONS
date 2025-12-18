#include<bits/stdc++.h>
using namespace std;
int val = 1000000007;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin  >> n >> x;
    int v[n];
    for(int i = 0;i<n;i++) cin >> v[i];

    vector<ll> dp(x+1,0);
    dp[0] = 1;
    for(int i = 1;i<=x;i++){
        for(int j = 0;j<n;j++){
            if(i-v[j] >= 0)
                dp[i] = (dp[i] + dp[i-v[j]]);
        }
        dp[i]%=val;
    }
    cout << dp[x] << endl;
}