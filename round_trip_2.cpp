#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<vector<int>>& v,vector<int>& vis,vector<int>& parent){
    vis[node] = 1;

    for(auto i : v[node]){
        if(vis[i] == 0){
            parent[i] = node;
            if(dfs(i,v,vis,parent)) return true;
        }
        else if(vis[i]==1){
            vector<int> cycle;
            cycle.push_back(i);
            int cur = node;
            while(cur!=i){
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(i);
            cout << cycle.size() << endl;
            for(int j = cycle.size()-1;j>=0;j--) cout << cycle[j] << " ";
            cout << endl;
            return true;
        }
    }
    vis[node] = 2;
    return false;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> vis(n+1,0);
    vector<vector<int>> v(n+1);
    vector<int> parent(n+1,-1);
    for(int i =0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    bool found = false;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
           if(dfs(i,v,vis,parent)){
            found = true;
               break;
           }
        }   
    }
     if(!found) cout << "IMPOSSIBLE";
    cout << endl;
    
}