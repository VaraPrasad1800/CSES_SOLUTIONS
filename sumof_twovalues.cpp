#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& a,pair<int,int>& b){
    return a.first<b.first;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
       cin >> v[i].first;
       v[i].second = i;
    }

    sort(v.begin(),v.end(),cmp);
    int left = 0;
    int right = n-1;
    bool found  = false;
    while(left<right){
        int sum = v[left].first + v[right].first;
        if(sum==k){
            cout << v[left].second + 1 << " " << v[right].second + 1 << endl;
            found = true;
            break;
        }
        else if(sum>k){
            right--;
        }
        else left++;
    }
    if(!found) cout << "IMPOSSIBLE" << endl;

}