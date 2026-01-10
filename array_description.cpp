#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int val = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    if(v[1]==0) {
        for(int j= 1;j<=m;j++) {
            dp[1][j] = 1;
        }
    }
    else{
        dp[1][v[1]] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (v[i] != 0 && v[i]!=j) continue;
            dp[i][j] = dp[i-1][j];
            if(j>1) dp[i][j]=(dp[i][j] + dp[i-1][j-1])%val;
            if(j<m) dp[i][j]=(dp[i][j] + dp[i-1][j+1])%val;
        }
    }
    ll ans = 0;
    if (v[n]==0) {
        for (int j = 1; j <= m; j++) {
            ans =(ans+dp[n][j])%val;
        }
    }
    else{
        ans = dp[n][v[n]];
    }

    cout << ans << endl;
}
