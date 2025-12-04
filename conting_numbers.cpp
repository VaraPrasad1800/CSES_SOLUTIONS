#include<bits/stdc++.h>
using namespace std;

int main(){
   long long n;
   cin >> n;
   n = n+1;
   long long count = 0;
   for(int i = 0;i<60;i++){
      long long val = (1LL << i+1);
      count+=(n/(val))*(val/2) +((n%val) - val/2 >=0? (n%val) - val/2 : 0LL) ;
   }
   cout << count << endl;
}