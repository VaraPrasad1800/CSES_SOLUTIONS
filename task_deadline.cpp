#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& a,pair<int,int>& b){
    return  a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),cmp);

    long long time = 0;
    long long reward = 0;
    
    for(int i = 0;i<n;i++){
        time+=v[i].first;
        reward+=(v[i].second-time);
    }
    cout << reward << endl;
}