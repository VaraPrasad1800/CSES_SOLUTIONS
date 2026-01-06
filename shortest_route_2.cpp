#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m,q;
    cin >> n >> m >> q;

    vector<vector<ll>> v(n+1,vector<ll>(n+1,LLONG_MAX));

    for(int i=0;i<m;i++){
        int a,b;
        ll w;
        cin >> a >> b >> w;
        v[a][b] = min(w,v[a][b]);
        v[b][a] = min(w,v[b][a]);
    }
    for(int i=1;i<=n;i++) v[i][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(v[j][i] != LLONG_MAX && v[i][k] != LLONG_MAX){
                     v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
                }
            }
        }
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        cout << (v[a][b]!=LLONG_MAX? v[a][b]:-1) << endl;
    }
}