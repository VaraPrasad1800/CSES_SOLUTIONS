#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> v(n+1);

    for(int i=0;i<m;i++){
        ll a,b,d;
        cin >> a >> b >> d;
        v[a].push_back({d,b});
    }
    vector<long long> dis(n+1,LLONG_MAX);
    dis[1] = 0;
    priority_queue<pair<ll,long long>,vector<pair<ll,long long>>,greater<pair<ll,long long>>> q;
    q.push({0,1});
    while(!q.empty()){
        ll city = q.top().second;
        ll Dis  = q.top().first;
        q.pop();
        if(Dis!=dis[city]) continue;
        for(auto i : v[city]){
            int next_city = i.second;
            int Distance = i.first;

            if(dis[next_city] > Dis+Distance){
                dis[next_city] = dis[city]+Distance;
                q.push({dis[next_city],next_city});
            }
        }
    }
    for(int i=1;i<=n;i++) cout << dis[i] << " ";
    cout << endl;

}