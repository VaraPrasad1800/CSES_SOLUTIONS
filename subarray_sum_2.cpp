#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    map<long long,long long> mpp;
    vector<long long> prefix(n);
    prefix[0] = v[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + v[i];
    }
    mpp[0]++;
    long long cnt = 0;
    for(int i=0;i<n;i++){
        if(!mpp.empty() && mpp.find(prefix[i]-x) != mpp.end()){
            auto pos = mpp.find(prefix[i]-x);
            cnt+=(pos->second);
        }
        mpp[prefix[i]]++;
    }

    cout << cnt << endl;
}