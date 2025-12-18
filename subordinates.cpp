#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>& v,vector<int>& dep){
    for(auto i : v[node]){
        dfs(i,v,dep);
        dep[node]+=dep[i]+1;
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> dep(n+1,0);
    vector<vector<int>> v(n+1);
    for(int i = 2;i<=n;i++){
        int k;
        cin >> k;
        v[k].push_back(i);
    }
    dfs(1,v,dep);
    for(int i = 1;i<=n;i++){
        cout << dep[i] << " ";
    }
    cout << endl;
    
}