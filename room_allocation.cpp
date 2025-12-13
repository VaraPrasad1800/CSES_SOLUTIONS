#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    long long cnt = 1;
    vector<int> ans(n);
    ans[v[0].second] = 1;
    minheap.push({v[0].first.second,1});
    for(int i =1;i<n;i++){
        if(v[i].first.first > minheap.top().first){
            ans[v[i].second] = minheap.top().second;
            minheap.pop();
            minheap.push({v[i].first.second,ans[v[i].second]});
        }
        else{
            cnt++;
            ans[v[i].second] = cnt;
            minheap.push({v[i].first.second,cnt});
        }
    }
    cout << cnt << endl;
    for(int i =0;i<n;i++) cout << ans[i] <<" ";
    cout << endl;
}