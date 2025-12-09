#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());

    if(n%2){
        int k = n/2;
        long long ans = 0;
        for(int i = 0;i<n;i++) ans+=abs(v[i]-v[k]);
        cout << ans << endl;
    }
    else{
        int k = n/2;
        long long ans1 = 0;
        for(int i = 0;i<n;i++) ans1+=abs(v[i]-v[k]);
        k--;
        long long ans2 = 0;
        for(int i = 0;i<n;i++) ans2+=abs(v[i]-v[k]);
        cout << min(ans1,ans2) << endl;
    }
}