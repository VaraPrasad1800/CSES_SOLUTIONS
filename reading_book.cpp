#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long maxtime = LLONG_MIN;
    long long total = 0;
    for(int i = 0;i<n;i++){
        long long k;
        cin >> k;
        total+=k;
        maxtime = max(maxtime,k);
    }
    if(total - maxtime < maxtime ) cout << 2*maxtime << endl;
    else cout << total << endl;
}