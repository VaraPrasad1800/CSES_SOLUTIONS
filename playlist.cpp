#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int> mpp;
    int length = 0;
    int left = 0;
    for(int i = 0;i<n;i++){
       int k;
       cin >> k;
       if(mpp.find(k) != mpp.end()){
           left = max(left,mpp[k]+1);
       }
       mpp[k] = i;
       length = max(length,i-left+1);
    }
    cout << length << endl;
}