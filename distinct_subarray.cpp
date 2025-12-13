#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0;i<n;i++) cin >> v[i];
    int left = 0;
    int right = 0;
    map<int ,int> mpp;
    long long  cnt = 0;
    while(right<n){
        if(mpp.find(v[right]) != mpp.end()){
            left = max(left,mpp[v[right]]+1);
        }
        mpp[v[right]] = right;
        cnt+=(right-left+1);
        right++; 
    }
    cout << cnt << endl;

    
}