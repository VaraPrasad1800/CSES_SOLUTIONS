#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        sum+=v[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    dp[0][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(dp[i-1][j]) dp[i][j] = true;
            else if( j-v[i-1] >= 0 && dp[i-1][j-v[i-1]]) dp[i][j] = true;
        }
    }
       vector<int> ans;
        for(int j=1;j<=sum;j++){
            if(dp[n][j]) ans.push_back(j); 
        }
        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << endl;
    
}