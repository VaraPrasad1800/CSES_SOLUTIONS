#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void seg_tree(int idx,int low,int high,vector<ll>& v,vector<ll>& seg){
    if(low==high) {
            seg[idx] = v[low];
            return;
    }
    int mid = low + (high-low)/2;
    seg_tree(2*idx+1,low,mid,v,seg);
    seg_tree(2*idx+2,mid+1,high,v,seg);
    seg[idx] = (seg[2*idx+1]+seg[2*idx+2]);
}
ll query(int idx,int low,int high,vector<ll>& v,vector<ll>& seg,vector<ll>& lazy,int k){
    if(lazy[idx]!=0){
        seg[idx] += (high-low+1)*lazy[idx];
        if(high!=low){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx] = 0;
    }
    int mid = low+(high-low)/2;
    if(low==high) return seg[idx];
    if(k<=mid) return query(2*idx+1,low,mid,v,seg,lazy,k);
    else return query(2*idx+2,mid+1,high,v,seg,lazy,k);
}
void update(int idx,int low,int high,vector<ll>& v,vector<ll>& seg,vector<ll>& lazy,int l,int r,int k){
    if(lazy[idx]!=0){
        seg[idx] += (high-low+1)*lazy[idx];
        if(high!=low){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(low>r || high<l) return ;
    if(low>=l && high<=r){
        seg[idx]+=(high-low+1)*k;
        if(high!=low){
            lazy[2*idx+1]+=k;
            lazy[2*idx+2]+=k;
        }
        return;
    }

    int mid = low + (high-low)/2;
      update(2*idx+1,low,mid,v,seg,lazy,l,r,k);
      update(2*idx+2,mid+1,high,v,seg,lazy,l,r,k);
      seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<ll> v(n),seg(4*n),lazy(4*n,0);
    for(int i=0;i<n;i++) cin >> v[i];
    seg_tree(0,0,n-1,v,seg);
    
    while(q--){
        int a;
        cin >> a ;
        if(a==1){
            int l,r,k;
            cin >> l >> r >> k;
            update(0,0,n-1,v,seg,lazy,l-1,r-1,k);
        }
        else{
          int k;
          cin >> k;
          cout << query(0,0,n-1,v,seg,lazy,k-1) << endl;
        }
    }
}