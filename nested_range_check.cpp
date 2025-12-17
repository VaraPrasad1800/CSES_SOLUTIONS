#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b){
    if(a.first.first == b.first.first) return a.first.second > b.first.second;
    else{
        return a.first.first < b.first.first;
    } 
}
int main(){
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i =0;i<n;i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(),v.end(),cmp);
    vector<int> ans1(n,0);
    int minEnd = v[n-1].first.second;
    for(int i = n-2;i>=0;i--){
          if(minEnd <= v[i].first.second){
            ans1[v[i].second] = 1;
          }
          minEnd = min(minEnd,v[i].first.second);
    }
    vector<int> ans2(n,0);
    int maxEnd = v[0].first.second;
    for(int i = 1;i<n;i++){
          if(v[i].first.second <= maxEnd){
            ans2[v[i].second] = 1;
          }
          maxEnd = max(maxEnd,v[i].first.second);
    }

    for(int i = 0;i<n;i++) cout << ans1[i] << " ";
    cout << endl;
    for(int i = 0;i<n;i++) cout << ans2[i] << " ";
    cout << endl;
}