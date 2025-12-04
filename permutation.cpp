#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 2 || n==3) cout << "NO SOLUTION" << endl;
    else{
        vector<int> v;
        for(int i = 2;i<=n;i++){
            if(i%2==0) v.push_back(i);
        }
        for(int i = 1;i<=n;i++){
            if(i%2) v.push_back(i);
        }
        for(int i = 0;i<n;i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}