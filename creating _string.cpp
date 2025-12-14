#include<bits/stdc++.h>
using namespace std;

long long factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}

int main(){
    string s;
    cin >> s;
    map<char,int> mpp;
    for(int i=0;i<s.size();i++) mpp[s[i]]++;

    string t = "";
    for(auto i:mpp){
        t+=string(i.second,i.first);
    }
    s = t;
    long long ans = factorial(s.size());

    for(auto i:mpp){
         ans = ans/factorial(i.second);
    } 
    cout << ans << endl;
    do{
         cout << t << endl;
       int n = t.size();
       int i ;
       for(i = n-2;i>=0;i--){
        if(t[i]<t[i+1]){
           break;
        } 
       }
       if(i<0) break;
        int k;
           for( k=n-1;k>i;k--){
            if(t[i]<t[k]) break;
           }
           swap(t[k],t[i]);
           reverse(t.begin()+i+1,t.end());
       
    }while(t!=s);
}