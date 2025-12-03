#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int x,a,b,c;
    cin >> x >> a >> b >> c;

    vector<long long> v;
    v.push_back(x);
    long long sum = x;
    for(int i = 2;i<=k;i++){
        long long val = (a*v.back()+b)%c;
        sum+=val;
        v.push_back(val);
    }
    long long sum_xor = sum ;
    for(int i = k+1;i<=n;i++){
        long long val = (a*v.back()+b)%c;
        v.push_back(val);
        sum = sum - v[i-(k+1)] + val;
        sum_xor^=sum;
    }

    cout << sum_xor << endl;
}