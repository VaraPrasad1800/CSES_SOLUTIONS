#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        long long y, x; 
        cin >> x >> y;

        long long n = max(y, x);
        long long m = (n - 1) * (n - 1);
        long long ans;

        if(n%2==0) {
            if(x==n)           
                ans = n*n -(y-1);
            else               
                ans = m + x;
        }
        else{
            if(y==n)           
                ans=n*n-(x - 1);
            else                 
                ans = m + y;
        }

        cout << ans << endl;
    }
}
