#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> v(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    long long ans = LLONG_MAX;
    for (int i = 0;i<(1 << n);i++) {
        long long s1 = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) s1 += v[j];
        }
        long long diff = abs(sum - 2*s1);
        ans = min(ans,diff);
    }
    cout << ans <<endl;
}
