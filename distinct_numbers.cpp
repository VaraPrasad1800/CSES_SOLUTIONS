#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int ,int> mpp;
    for(int i =0;i<n;i++){
        int k;
        cin >> k;
        mpp[k]++;
    }
    cout << mpp.size() << endl;
}