#include<bits/stdc++.h>
using namespace std;
 
void seg_tree(int idx,int low,int high,vector<int>& v,vector<int>& seg){
    if(low==high) {
            seg[idx] = v[low];
            return;
    }
    int mid = low + (high-low)/2;
    seg_tree(2*idx+1,low,mid,v,seg);
    seg_tree(2*idx+2,mid+1,high,v,seg);
    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
}
int query(int idx,int low,int high,vector<int>& v,vector<int>& seg,int l,int r){
    if(low>=l && high<=r) return seg[idx];
    else if(low>r || high<l) return INT_MAX;
    int mid = low+(high-low)/2;
    int left = query(2*idx+1,low,mid,v,seg,l,r);
    int right = query(2*idx+2,mid+1,high,v,seg,l,r);
    return min(left,right);
}
void update(int idx,int low,int high,vector<int>& v,vector<int>& seg,int k,int u){
    if(low==high) {
        seg[idx] = u;
        return;
    }
    
    int mid = low + (high-low)/2;
       if(k<=mid) update(2*idx+1,low,mid,v,seg,k,u);
       else  update(2*idx+2,mid+1,high,v,seg,k,u);
      seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> v(n),seg(4*n);
    for(int i=0;i<n;i++) cin >> v[i];
    seg_tree(0,0,n-1,v,seg);
    
    while(q--){
        int a,l,r;
        cin >> a >> l >> r;
        if(a==1){
            update(0,0,n-1,v,seg,l-1,r);
        }
        else
          cout << query(0,0,n-1,v,seg,l-1,r-1) << endl;
    }
}