#include<bits/stdc++.h>
using namespace std;

bool  bfs(int x,vector<int>& grp,vector<vector<int>>& v){
    queue<int> q;
    q.push(x);
    grp[x] = 1;
    bool found = false;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:v[node]){
            if(grp[i] == -1){
               grp[i] = 3 - grp[node];
               q.push(i);
            }
            else if(grp[i] == grp[node]) return false;
            
        }
    }
    return true;
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
    vector<int> grp(n+1,-1);
    bool found = false;
    for(int i=1;i<=n;i++){
        if(grp[i] == -1){
            if(!bfs(i,grp,v)){
              cout << "IMPOSSIBLE" << endl;
              found = true;
              break;
            }
        }
    }

    if(!found){
        for(int i=1;i<=n;i++){
            cout << grp[i] << " ";
        }
        cout << endl;
    }
  
    
}