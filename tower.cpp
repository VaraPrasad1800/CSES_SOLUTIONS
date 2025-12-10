#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0;i<n;i++){
        int k;
        cin >> k;
        auto it = s.upper_bound(k);
        if(it == s.end()){
            s.insert(k);
        }
        else{
             s.erase(it);
             s.insert(k);
        }
    }
    cout << s.size() << endl;
}