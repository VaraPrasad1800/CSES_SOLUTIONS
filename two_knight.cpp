#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    for (long long k = 1;k<=n;k++){
        long long Tpairs = k*k*(k*k - 1)/2;
        long long Apairs   = 4*(k - 1)*(k - 2); 
        cout << Tpairs - Apairs << endl;;
    }
}
