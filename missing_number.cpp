#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long mis = 0;
    for(int i=0;i<n-1;i++){
        int k;
        cin >> k;
        mis^=k;
    }
    for(int i = 1;i<=n;i++) mis^=i;
    cout << mis << endl;
}