#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int x,a,b,c;
    cin >> x >> a >> b >> c;

    deque<int> q;
    vector<long long> v;
    v.push_back(x);
    q.push_back(0);
    for(int i = 2;i<=k;i++){
        long long val = (a*v.back()+b)%c;
        v.push_back(val);
        while(!q.empty() && val < v[q.back()]){
            q.pop_back();
        }
        q.push_back(i-1);  
    }
    long long sum_xor = v[q.front()];
    for(int i = k+1;i<=n;i++){
        long long val = (a*v.back()+b)%c;
        v.push_back(val);
        if(q.front() == (i-k-1) ) q.pop_front();
        while(!q.empty() && val < v[q.back()]){
            q.pop_back();
        }
        q.push_back(i-1);
        sum_xor^= v[q.front()];
    }

    cout << sum_xor << endl;
}