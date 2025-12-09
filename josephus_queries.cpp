#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k) {
    if (n == 1) return 1;
    ll h = (n + 1)/2;
    if (k<=h) {
        ll x = 2*k;
        if (x>n) x = x%n;
        return x;
    }
    ll t = solve(n / 2, k - h);
    return (n & 1) ? 2*t + 1 : 2*t - 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}
