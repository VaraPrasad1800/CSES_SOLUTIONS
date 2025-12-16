#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;

        if (a + b > n ||(a == 0 && b > 0)|| (b == 0 && a > 0)) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            int k = a+b;
            for (int i =1;i<=n;i++) cout << i << " ";
            cout << endl;
            vector<int> v(n + 1);

            if (k == 0) {
                for (int i =1;i<=n;i++) v[i] = i;
            } else {
                for (int i = 1;i<= k;i++) v[i] = ((i+a-1)%k) + 1;
                for (int i = k+1;i<=n;i++) v[i] = i;
            }
            for (int i = 1;i<=n;i++) cout << v[i] << " ";
            cout << endl;
        }
    }
}
