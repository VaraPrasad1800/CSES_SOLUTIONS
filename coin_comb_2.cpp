#include<bits/stdc++.h>
using namespace std;
int val = 1000000007;
typedef long long ll;
ll mod = LLONG_MAX;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin  >> n >> x;
    int v[n];
    for(int i = 0;i<n;i++) cin >> v[i];
 
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i = 0;i<n;i++){
        for(int j =v[i];j<=x;j++){
                if((dp[j] + dp[j-v[i]]) >= val) dp[j] = (dp[j] + dp[j-v[i]])%val; 
                else dp[j] = (dp[j] + dp[j-v[i]]);        
        }
        
    }
    cout << dp[x] << endl;
}