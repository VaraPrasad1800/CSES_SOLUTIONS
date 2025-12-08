#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll s = n * (n + 1) / 2;
    if (s % 2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        s = s / 2;
        ll cur = 0, last = n;
        vector<int> a , b;
        vector<int>  v(n + 1, 0);
        while (cur < s){
            ll rem = s - cur;
            if (rem > last){
                a.push_back(last);
                v[last] = 1;
                cur += last;
                last--;
            }
            else{
                a.push_back(rem);
                v[rem] = 1;
                cur = s;
            }
        }
        for (int i = 1;i<=n;i++)
            if (!v[i]) b.push_back(i);

        cout << a.size() << endl;
        for (int x : a) cout << x << " ";
        cout << endl;
        cout << b.size() << endl;
        for (int x : b) cout << x << " ";
    }
}