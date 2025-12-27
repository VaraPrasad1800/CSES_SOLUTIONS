#include<bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp){
    long long res = 1;
    while(exp){
        if(exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long digit = 1;
        long long num = 9;
        while(n-digit*num > 0){
            n-=digit*num;
            digit++;
            num*=10;
        }
        long long target = power(10,digit-1) + (n-1)/digit;
        long long idx = n%digit;
        if(idx!=0)
           target = target/power(10,digit-idx);
        cout << target%10 << endl;
    }
    
}