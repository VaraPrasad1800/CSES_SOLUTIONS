#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end());
    int sum ;
    bool found = false;
    for(int i = 0;i<n;i++){
        sum = k-v[i].first;
        int low = i+1;
        int high = n-1;
        while(low<high){
                int val = v[low].first + v[high].first;
                if(sum == val ){
                    cout << v[i].second << " "<< v[low].second <<" " << v[high].second << endl;
                    found = true;
                    break;
                }
                else if(sum > val) low++;
                else high --;
            } 
        if(found) break;      
    }
    if(!found) cout << "IMPOSSIBLE" << endl;
}