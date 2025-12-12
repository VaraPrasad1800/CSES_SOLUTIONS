#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n),pos(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pos[v[i]] = i;
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(pos[i] > pos[i+1]) ans++;
    }
    cout << ans;
}
