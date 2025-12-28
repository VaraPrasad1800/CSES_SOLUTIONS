#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int& cnt,vector<vector<int>>& v,vector<int>& vis,int par,vector<int>& rep){
    if(rep[node]!=-1) return;
    rep[node] = 1;
    if(v[node].size() == 0){
        if(vis[par]==-1){
            cnt++;
            vis[par] = 1;
            vis[node] = 1;
        }
    }
    for(auto i:v[node]){
        dfs(i,cnt,v,vis,node,rep);
    }
    if(vis[node] == -1 && vis[par] == -1){
        cnt++;
        vis[node] = vis[par] = 1;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> rep(n+1,-1);
    vector<int> vis(n+1,-1);
    int cnt = 0;
    dfs(1,cnt,v,vis,-1,rep);
    cout << cnt << endl;
  


}

