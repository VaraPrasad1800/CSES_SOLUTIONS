#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void seg_tree(vector<ll>& seg,vector<ll>& hos,int idx,int low,int high){
    if(low == high){
        seg[idx] =  hos[low];
        return ;
    }
    int mid = low + (high-low)/2;
    seg_tree(seg,hos,2*idx+1,low,mid);
    seg_tree(seg,hos,2*idx+2,mid+1,high);

    seg[idx] = max(seg[2*idx+1] , seg[2*idx+2]);
}

int query(vector<ll>& seg, int idx, int low, int high, ll val){
    if(seg[idx] < val) return -1;

    if(low == high){
        seg[idx] -= val;
        return low;
    }

    int mid = (low + high) / 2;
    int res;

    if(seg[2*idx+1] >= val)
        res = query(seg, 2*idx+1, low, mid, val);
    else
        res = query(seg, 2*idx+2, mid+1, high, val);

    seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    return res;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> hos(n);
    for(int i=0;i<n;i++) cin >> hos[i];
    vector<ll> grp(m);
    for(int i=0;i<m;i++) cin >>grp[i];
    vector<ll> seg(4*n);
    
    seg_tree(seg,hos,0,0,n-1);
    for(int i=0;i<m;i++){
      int ans = query(seg,0,0,n-1,grp[i]);
      if(ans == -1) cout << 0 << " ";
      else cout << ans+1 << " ";
    }
    cout << endl;
}