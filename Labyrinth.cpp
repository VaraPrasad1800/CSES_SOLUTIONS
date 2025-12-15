#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> idx(2);
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<char>> dir(n,vector<char>(m));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));
    vector<vector<int>> dis(n,vector<int>(m,-1));
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<char> direction = {'R','D','L','U'};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
            if(v[i][j] == 'A') {
                idx[0].first = i;
                idx[0].second = j;
            }
            if(v[i][j] == 'B'){
                idx[1].first = i;
                idx[1].second = j;
            }
        }
    }
        queue<pair<int,int>> q;
        q.push({idx[0].first,idx[0].second});
        dis[idx[0].first][idx[0].second] = 0;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i == idx[1].first && j == idx[1].second){
                cout << "YES" << endl;
                cout << dis[i][j] << endl;
                string path = "";
                int x = i;
                int y = j;
                while(x!= idx[0].first || y!=idx[0].second){
                    path+=dir[x][y];
                    int px = parent[x][y].first;
                    int py = parent[x][y].second;
                    x = px;
                    y =  py;
                }
                reverse(path.begin(),path.end());
                cout << path << endl;
                return 0;
            }
             
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny>= m) continue;
                if(v[nx][ny] == '#') continue;
                if (dis[nx][ny] != -1) continue;

                dis[nx][ny] = dis[i][j] + 1;
                parent[nx][ny] = {i,j};
                dir[nx][ny] = direction[k];
                q.push({nx, ny});
            }

        }
        cout << "NO" << endl;
    }

