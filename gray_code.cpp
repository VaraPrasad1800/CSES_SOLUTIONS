#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0;i<(1<<n);i++){
        int k = i^(i>>1);
        for(int j =n-1;j>=0;j--){
            bool bit = (1<<j) & k;
               if(bit) cout << "1";
               else cout <<"0";
        }
        cout << endl;
    }
}