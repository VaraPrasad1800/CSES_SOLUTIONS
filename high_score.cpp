#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<long long> vis(n+1, LLONG_MAX);
    vector<pair<int,pair<int,int>>> v;
    vector<vector<int>> rev(n+1);

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back({a, {b, -w}}); 
        rev[b].push_back(a);     
    }

    vis[1] = 0;
    for(int i = 1; i < n; i++){
        for(auto j : v){
            int u = j.first;
            int vv = j.second.first;
            int w = j.second.second;

            if(vis[u] != LLONG_MAX && vis[u] + w < vis[vv]){
                vis[vv] = vis[u] + w;
            }
        }
    }
    vector<int> reach(n+1, 0);
    for(auto j : v){
        int u = j.first;
        int vv = j.second.first;
        int w = j.second.second;

        if(vis[u] != LLONG_MAX && vis[u] + w < vis[vv]){
            reach[vv] = 1;
        }
    }
    vector<int> Reach(n+1,0);
    stack<int> st;
    st.push(n);
    Reach[n] = 1;

    while(!st.empty()){
        int x = st.top();
        st.pop();

        for(auto y:rev[x]){
            if(!Reach[y]){
                Reach[y] = 1;
                st.push(y);
            }
        }
    }
    bool found = false;
    for(int i=1;i<=n;i++){
        if(reach[i] && Reach[i]){
            cout << -1 << endl;
            found = true;
            break;
        }
    }

    if(!found) cout << -vis[n] << endl;
}
