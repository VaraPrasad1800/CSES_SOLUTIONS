#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int left = 0;
    int right = 0;
    int cnt = 0;
    int MaxLength = 0;
    while(right<s.size()){
        if(s[right]==s[left]){
            cnt++;
             right++;
        }
        else{
            MaxLength = max(MaxLength,cnt);
            cnt = 0;
            left = right;
        }
       
    }
    MaxLength = max(MaxLength,cnt);
    cout << MaxLength << endl;

}