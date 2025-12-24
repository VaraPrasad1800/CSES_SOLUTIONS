#include<bits/stdc++.h>
using namespace std;
 
void dfs(int idx,vector<int>& dis,vector<int>& vis,vector<vector<int>>& v){
    if(vis[idx]!=-1) return;
    vis[idx] = 1;
    for(auto i : v[idx]){
        if(vis[i]!=-1) continue;
        dis[i] = dis[idx]+1;
        dfs(i,dis,vis,v);
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
   vector<int> dis(n+1,0);
   vector<int> vis(n+1,-1);
   dis[1] = 0;
   dfs(1,dis,vis,v);
   int maxD = dis[1];
   int node = 1;
   for(int i=1;i<=n;i++){
        if(dis[i]>maxD){
            maxD = dis[i];
            node = i;
        }
   }
   vector<int> Dis(n+1,0);
   vector<int> Vis(n+1,-1);
   Dis[node] = 0;
   dfs(node,Dis,Vis,v);
    int ans = dis[1];
     for(int i=1;i<=n;i++){
        if(Dis[i]>ans){
            ans = Dis[i];
        }
     }
     cout << ans << endl;

}