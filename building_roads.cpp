#include<bits/stdc++.h>
using namespace std;

void dfs(int idx,vector<vector<int>>& v,vector<int>& vis){
    vis[idx] = 1;
    for(auto i:v[idx]){
        if(vis[i]==-1) dfs(i,v,vis);
    }
    return;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> vis(n+1,-1);
    dfs(1,v,vis);
    int cnt = 0;
    vector<pair<int,int>> road;
    for(int i=2;i<=n;i++){
        if(vis[i]==-1){
            dfs(i,v,vis);
            cnt++;
            road.push_back({i-1,i});
        }
    }
    cout << cnt << endl;
    for(auto i:road){
        cout  << i.first << " " << i.second << endl;
    }
    cout << endl;
    
}