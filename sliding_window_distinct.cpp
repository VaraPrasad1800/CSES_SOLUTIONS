#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    map<int,int> mpp;

    for(int i = 0;i<k;i++) mpp[v[i]]++;
    cout << mpp.size() << " ";

    for(int i=k;i<n;i++){
        mpp[v[i]]++;
        mpp[v[i-k]]--;
        if(mpp[v[i-k]] == 0) mpp.erase(v[i-k]);
        cout << mpp.size() << " ";
    }
    cout << endl;
}
//3 2 3 2 2 1