#include<bits/stdc++.h>
using namespace std;

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
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    vector<int> dis(n+1,0);
    vector<int> parent(n+1);
    parent[1] = -1;
    dis[1] = 1;
    bool found = false;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:v[node]){
            if(vis[i] == -1){
                vis[i] = 1;
                dis[i] = dis[node]+1;
                parent[i] = node; 
                if(i == n){
                        found = true;
                        cout << dis[i] << endl;
                        vector<int> path;
                        path.push_back(i);
                        int cur = node;
                                while(cur!=1){
                                    path.push_back(cur);
                                    cur = parent[cur];
                                }
                        path.push_back(1);
                        reverse(path.begin(),path.end());
                                for(auto p : path){
                                    cout << p << " ";
                                }
                        cout << endl;
                        break;
                }   
                q.push(i);
            }
        }
    }
    if(!found) cout << "IMPOSSIBLE" << endl;


    
}