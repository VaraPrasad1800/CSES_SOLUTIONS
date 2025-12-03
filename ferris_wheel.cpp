#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int left = 0;
    int right = n-1;
    int cnt = 0;
    int weight = 0;
    int number = 0;
    while(left<=right){
      if(weight<v[left] || number==2){
        weight = x;
        number = 0;
        cnt++;
      }
     if(v[left]+v[right] <= weight && number==0){
        weight-=(v[left]+v[right]);
        left++;
        right--;
        number = 2;
     }
     else if(v[right] <= weight && number <=1){
        weight-=v[right];
        right--;
        number++;
     }
     else if(v[left] <= weight && number <=1){
        weight-=v[left];
        left++;
        number++;
     }

    }
    cout << cnt << endl;
}