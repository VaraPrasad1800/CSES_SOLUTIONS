#include<bits/stdc++.h>
using namespace std;
int val = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    map<int,int> mpp;
    long long ans = 1;
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
    }
    for(auto i:mpp){
        ans = (ans*(i.second+1))%val;
    }
    ans = (ans-1)%val;
    cout << ans << endl;
}