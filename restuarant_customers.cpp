#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>& b){
    return a.first<b.first;
}

int main(){
    int n ;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(v[0].second);
    for(int i=1;i<n;i++){
        if(v[i].first > minheap.top()){
            minheap.pop();
            minheap.push(v[i].second);
        }
        else{
             minheap.push(v[i].second);  
        }
    }
    cout << minheap.size() << endl;
}