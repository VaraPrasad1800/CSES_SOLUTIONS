#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int maxE = 0;
    for(int i = 0;i<n;i++) {
        cin >> v[i];
        maxE = max(maxE,v[i]);
    }

    vector<int> freq(maxE+1,0);
    for(int i = 0;i<n;i++) freq[v[i]]++;
    bool found = false;
     for(int i =maxE;i>=1;i--){
        int cnt = 0;
        for(int j = i;j<=maxE;j+=i){
             cnt+=freq[j];
             if(cnt>=2){
                found = true;
                cout << i << endl;
                break;
             }
        }
        if(found) break;
     }
}