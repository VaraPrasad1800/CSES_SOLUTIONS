#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& x,vector<vector<int>>& v,int i,int j,vector<int>& path,vector<int>& a){
    if(i==0 || j==0){
        return ;
    }
    
    if(x[i][j]==0){
        path.push_back(a[i-1]);
        print(x,v,i-1,j-1,path,a);
    }
    else if(x[i][j] == 1){
        print(x,v,i-1,j,path,a);
    }
    else print(x,v,i,j-1,path,a);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    vector<vector<int>> v(n+1,vector<int>(m+1,0)),x(n+1,vector<int>(m+1,0));
    vector<int> path;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                v[i+1][j+1] = 1+v[i][j];
            }
            else{
                v[i+1][j+1] = max(v[i][j+1],v[i+1][j]);
                if(v[i][j+1] >= v[i+1][j]){
                    x[i+1][j+1] = 1;
                }
                else x[i+1][j+1] = 2;
            }
        }
    }
    cout << v[n][m] << endl;
    print(x,v,n,m,path,a);
    reverse(path.begin(),path.end());
    for(auto i : path){
        cout << i << " ";
    }
    cout << endl;

 
}