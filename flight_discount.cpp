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
    vector<vector<ll>> dis(n+1, vector<ll>(2,LLONG_MAX));
    dis[1][0] = 0;
    priority_queue<pair<ll,pair<long long,int>>,vector<pair<ll,pair<long long,int>>>,greater<pair<ll,pair<long long,int>>>> q;
    q.push({0,{1,0}});
    while(!q.empty()){
        ll city = q.top().second.first;
        ll Dis  = q.top().first;
        ll used = q.top().second.second;
        q.pop();
        if(Dis!=dis[city][used]) continue;
        for(auto i : v[city]){
            int next_city = i.second;
            int Distance = i.first;
            
            if(dis[next_city][used] > Dis+Distance){
                dis[next_city][used] = dis[city][used]+Distance;
                q.push({dis[next_city][used],{next_city,used}});
            }
            if(used == 0 && dis[next_city][1] > Dis+(Distance/2)){
                dis[next_city][1] = dis[city][used] + (Distance/2);
                q.push({dis[next_city][1],{next_city,1}});
            }
        }
    }
    cout << min(dis[n][0],dis[n][1]) << " ";
    cout << endl;

}