#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<int>> dis(n,vector<int>(m,-1));
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }

    int rooms = 0;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == '.' && dis[i][j] == -1){
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                     
                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny>= m) continue;
                        if(v[nx][ny] == '#') continue;
                        if (dis[nx][ny] != -1) continue;
                        dis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                rooms++;
            }
        }
    }
    cout << rooms << endl;
}