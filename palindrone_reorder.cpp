#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();
    map<char,int> mpp;
    for(int i = 0;i<n;i++) mpp[s[i]]++;
    int cnt = 0;
    for(auto i : mpp){
        if(i.second%2) cnt ++;
    }
    
    if(cnt >1 || (cnt==1 && n%2==0)){
        cout << "NO SOLUTION" << endl;
    }
    else{
       int count = 0;
       for(auto i : mpp){
            if(i.second%2){
            s[n/2] = i.first;
            i.second--;
            }
            if(i.second>0){
                while(i.second > 0){
                    s[count] = i.first;
                    s[n-1-count] = i.first;
                    count++;
                    i.second-=2;
                }
            }
       }
           for(int i = 0;i<n;i++) cout << s[i];
             cout << endl;
    }

}