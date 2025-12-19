#include<bits/stdc++.h>
using namespace std;
int val = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<vector<char>> v(n,vector<char>(n));
    vector<vector<int>> dis(n,vector<int>(n,-1));
    vector<int> dx = { 1, 0};
    vector<int> dy = { 0,1};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }

    dis[0][0]  = 1;
   if(v[0][0]=='*'){
    cout << 0 << endl;
   }
   else{
    bool found = false;
                queue<pair<int,int>> q;
                q.push({0,0});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(x==n-1 && y == n-1){
                        found = true;
                        cout << dis[x][y] << endl;
                        break;
                    }
                    for(int k = 0; k < 2; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if ( nx >= n || ny>= n) continue;
                        if(v[nx][ny] == '*') continue;
                        if (dis[nx][ny] != -1){
                            dis[nx][ny] = (dis[nx][ny]+dis[x][y])%val;
                        }
                        else{
                             q.push({nx, ny});
                             dis[nx][ny] = dis[x][y];
                        }
                       // dis[nx][ny] = 1;
                       
                    }
                }
                if(!found)
                    cout << 0 << endl;
   }

}