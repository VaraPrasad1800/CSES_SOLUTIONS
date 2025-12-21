#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first;
    for(int i=0;i<n;i++) cin >> v[i].second;

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
     
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j-v[i-1].first >=0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1].first] + v[i-1].second);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][x] << endl;

}