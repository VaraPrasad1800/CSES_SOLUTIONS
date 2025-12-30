#include<bits/stdc++.h>
using namespace std;
int val = 1000000007;
const int Size = 1000001;

long long factorial[Size],inverse[Size];

long long power(long long base,long long exp){
    long long ans = 1;
    while(exp){
        if(exp & 1) ans = (ans*base)%val;
        base = (base*base)%val;
        exp >>= 1;
    }
    return ans%val;

}

int main(){
    int n;
    cin >> n;

    factorial[0] = 1;
    for(int i=1;i<Size;i++){
        factorial[i] = (factorial[i-1]*i)%val;
    }

    inverse[Size-1] = power(factorial[Size-1],val-2);

    for(int i=Size-2;i>=0;i--){
        inverse[i] = (inverse[i+1]*(i+1) )%val;
    }


    while(n--){
        long long a,b;
        cin >> a >> b;

        cout << (factorial[a]%val * inverse[b]%val * inverse[a-b]%val)%val;
        cout << endl;
        
    }
}