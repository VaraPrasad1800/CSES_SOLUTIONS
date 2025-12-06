#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    multiset<int> prize;
    for(int i  =0;i<n;i++){
        int k;
        cin >> k;
        prize.insert(k);
    }
    for(int i = 0;i<m;i++){
        int k;
        cin >> k;
        auto j  = prize.upper_bound(k);
        if(j == prize.begin()){
            cout << "-1" << endl;
        }
        else{
            j--;
            cout << *j << endl;
            prize.erase(j);
        }
    }





}